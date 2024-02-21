#ifndef JOBS_CORE_H
#define JOBS_CORE_H

#include "../parser/parser.h"

/* ENUM */

typedef enum { RUNNING, STOPPED, DETACHED, KILLED, DONE } Status;

/* STRUCTURES */

typedef struct process {
    pid_t pid;
    Status status;
    command *cmd;
    command_without_substitution *cmd_without_subst;
} process;

typedef struct job {
    unsigned id;
    pid_t pgid;
    pid_t pid_leader;
    Status status;
    pipeline *pipeline;
    process **job_process;
    size_t process_number;
} job;

/* VARIABLES */

extern int job_number;
extern job **jobs;

/* FUNCTIONS */

void free_job(job *);

char *simple_str_of_job(job *, bool);
/**
 * Prints all informations from a job on a single line
 * For example :
 * [4] 591141  Running  ./a.out | wc -l > /tmp/tutu
 * The bool argument tells the function if the job is new,
 * in which case there is less spaces than usual
 */

void print_job(job *, bool);
/**
 * Print the job, and add '+' if it's a new one
 */

job *init_job_to_add(pid_t, pid_t, pipeline *, Status);
/**
 * Init a new job, which could be add to jobs
 */

void free_jobs_core();
/* Free allocation of all jobs and their pipelines */

char *state_to_string(Status);
/* From a status, returns the corresponding string */

int get_jobs_placement_with_id(unsigned);
/* Returns the position in the job list of the job carrying the corresponding job id,
 * or -1 if it isn't present*/

int add_job_to_jobs(job *);
/* Adds a new job to the job list, and returns SUCCESS if the command succeeds */

int add_process_to_job(job *, pid_t, command *, command_without_substitution *, Status);
/* Adds a new process to the job containing the id */

int remove_job_from_jobs(unsigned);
/* Removes the job with the given id from the list, and returns SUCCESS if the command succeeds,
 * COMMAND_FAILURE if the job is not found */

void remove_terminated_jobs(bool);
/* Removes jobs from list if done, detached or killed and print it if true is given */

void update_status_of_jobs();
/* Updates job status according to waitpid */
#endif
