#ifndef CUSTOM_GETLINE_H
#define CUSTOM_GETLINE_H

#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>

/* Copy source into *lineptr, resizing *lineptr if needed.
 * On success returns number of characters copied (excluding terminating NUL).
 * On error returns -1.
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif
