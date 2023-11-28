#ifndef EXIT_H
#define EXIT_H

#include "../parser/parser.h"

int exit_jsh(const command *cmd);
/* Exit the jsh program with the specified value
 * If no value is specified, exit the program with 
 * the value of the last executed command*/

#endif