#include "jobs_core.h"
#include "constants.h"
#include "core.h"
#include "int_utils.h"
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int job_number = 0;
job **jobs = NULL;

void free_job(job *j) {
    if (j == NULL) {
        return;
    }
    if (j->pipeline != NULL) {
        free_pipeline(j->pipeline);
    }
    free(j);
}

void free_jobs_core() {
    if (jobs != NULL) {
        for (size_t i = 0; i < job_number; i++) {
            free_job(jobs[i]);
        }
        free(jobs);
    }
}

char *state_to_string(Status status) {
    if (status == RUNNING) {
        return strdup("Running");
    }
    if (status == STOPPED) {
        return strdup("Stopped");
    }
    if (status == DETACHED) {
        return strdup("Detached");
    }
    if (status == KILLED) {
        return strdup("Killed");
    }
    return strdup("Done");
}

char *simple_str_of_job(job *j, bool new) {
    char *status = state_to_string(j->status);
    char *pipeline = str_of_pipeline(j->pipeline);

    int result_length;
    char *result;
    char *format;

    if (new) {
        format = strdup("[%u]   %d        %s %s");
    } else {
        format = strdup("[%u]   %d        %s    %s");
    }

    result_length = strlen(format) + strlen(status) + strlen(pipeline) + get_nb_of_digits(j->id) +
                    get_nb_of_digits(j->pid) - FORMAT_SPECIFIERS_CHARACTERS_COUNT;

    result = malloc(result_length * sizeof(char));
    snprintf(result, result_length, format, j->id, j->pid, status, pipeline);

    free(format);
    free(status);
    free(pipeline);

    return result;
}

void print_job(job *j, bool new) {
    if (j == NULL) {
        return;
    }
    char *strjb = simple_str_of_job(j, new);
    fprintf(stderr, "%s\n", strjb);
    free(strjb);
}

unsigned get_id_new_job() {
    unsigned id = 1;
    bool is_same_id = true;

    while (is_same_id) {
        is_same_id = false;
        for (size_t i = 0; i < job_number; i++) {
            if (jobs[i]->id == id) {
                is_same_id = true;
                id++;
                break;
            }
        }
    }
    return id;
}

job *init_job_to_add(pid_t pid, pipeline *pip, Status s) {
    unsigned id = get_id_new_job();

    job *new_job = malloc(sizeof(job));

    if (new_job == NULL) {
        return NULL;
    }
    new_job->pid = pid;
    new_job->status = s;
    new_job->id = id;
    new_job->pipeline = pip;

    return new_job;
}

int get_jobs_placement_with_id(unsigned id) {
    job *acc;
    for (int i = 0; i < job_number; i++) {
        acc = jobs[i];
        if (acc != NULL && acc->id == id) {
            return i;
        }
    }
    return -1;
}

int add_job_to_jobs(job *j) {
    if (jobs == NULL) {
        jobs = malloc(sizeof(job *));
        assert(jobs != NULL);
        jobs[0] = j;
        job_number++;
        return SUCCESS;
    }
    job **temp = malloc(sizeof(job *) * (job_number + 1));
    assert(temp != NULL);

    memmove(temp, jobs, job_number * sizeof(job *));
    temp[job_number] = j;

    free(jobs);
    jobs = temp;

    job_number++;

    return SUCCESS;
}

int add_new_forked_process_to_jobs(pid_t pid, pipeline *pip, Status s) {
    job *new_job = init_job_to_add(pid, pip, s);

    if (new_job == NULL) {
        return EXIT_FAILURE;
    }
    int res = add_job_to_jobs(new_job);

    if (res != 0) {
        return res;
    }
    print_job(new_job, true);
    return SUCCESS;
}

int remove_job_from_jobs(unsigned id) {
    if (jobs == NULL) {
        return COMMAND_FAILURE;
    }
    int job_placement = get_jobs_placement_with_id(id);

    if (job_placement < 0) {
        return COMMAND_FAILURE;
    }
    job **temp = malloc(sizeof(job *) * (job_number - 1));

    assert(temp != NULL);

    memmove(temp, jobs, job_placement * sizeof(job *));
    memmove(temp + job_placement, jobs + job_placement + 1, (job_number - job_placement - 1) * sizeof(job *));

    job *j_removed = jobs[job_placement];
    free_job(j_removed);

    free(jobs);
    jobs = temp;
    job_number--;

    if (job_number == 0) {
        free(jobs);
        jobs = NULL;
    }
    return SUCCESS;
}

int update_status_of_job(job *j) {
    int status;
    int res = waitpid(j->pid, &status, WNOHANG | WUNTRACED | WCONTINUED);

    if (res < 0) {
        assert(errno == ECHILD);

        j->status = DETACHED;
    } else if (res > 0) {
        if (WIFEXITED(status)) {
            j->status = DONE;
        } else if (WIFSIGNALED(status)) {
            j->status = KILLED;
        } else if (WIFSTOPPED(status)) {
            j->status = STOPPED;
        } else if (WIFCONTINUED(status)) {
            j->status = RUNNING;
            print_job(j, false);
        }
    }
    return SUCCESS;
}

void remove_terminated_jobs(bool print) {
    unsigned njob = job_number;
    for (int i = 0; i < job_number; i++) {
        job *j = jobs[i];

        if (j->status == DONE || j->status == KILLED || j->status == DETACHED) {
            if (print) {
                print_job(j, false);
            }
            remove_job_from_jobs(j->id);
            i--;
        }
    }

    if (njob != job_number) {
        update_prompt();
    }
}

void update_status_of_jobs() {
    for (size_t i = 0; i < job_number; i++) {
        update_status_of_job(jobs[i]);
    }
}
