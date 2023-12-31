#ifndef CORE_H
#define CORE_H

#include "../parser/parser.h"
#include "constants.h"
#include "jobs_core.h"

/* VARIABLES */

extern char *current_folder; // current user position, initialized with PWD from constant
extern char *prompt;         // command readout prompt
extern int last_command_exit_value;          // last user command exit value
extern char *last_reference_position;        // last user location, initialized with PWD from constant
extern char *last_line_read;                 // last line typed by the user
extern pipeline_list *current_pipeline_list; // current_pipeline run

/* FUNCTIONS */

void print_error(const char *);
// print the error message on error output

void update_prompt();
// update the prompt according to the current position

void init_core();
// initialize constants and then initialize the variables that need them: current_folder, prompt and
// last_reference_position

void free_core();
/* free memory allocation for variables pwd, prompt and last_reference_position other than NULL if different from value
NULL */

int change_pwd(const char *);
/* updates the pwd environment variable by changing it to the string passed as argument, and returns an error otherwise
 */

void update_current_folder();
/* Changes the folder variable current_folder to the reference of the current directory */

#endif
