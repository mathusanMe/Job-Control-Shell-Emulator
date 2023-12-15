#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

bool start_with(const char *, const char *);
/* Returns true if the first string begins with
 * the same characters as the second */

bool start_with_exception(const char *, const char *, char);
/* Returns true if the first string begins with
 * the same characters as the second not including the 
 * character at the beginning of the first */

char *concat_with_delimiter(const char *, const char *, char);
/* Returns the string of the two concatenated
 * strings separated by the character */

bool is_integer(const char *);
/* Returns true if the char * argument represents an integer */

bool has_sequence_of(const char *, char);
/* Returns true if the char * argument contains a sequence of the given char */

#endif
