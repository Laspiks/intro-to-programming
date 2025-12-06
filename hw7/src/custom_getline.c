#include "../include/custom_getline.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
if (!lineptr || !n) return -1;

    char *buf = *lineptr;
    size_t cap = *n;
    size_t len = 0;
    int c;

    if (!buf) {
        cap = 128;
        buf = (char*)malloc(cap);
        if (!buf) return -1;
    }

    while ((c = fgetc(stream)) != EOF) {
        if (len + 1 >= cap) {
            size_t new_cap = cap * 2;
            char *tmp = (char*)realloc(buf, new_cap);
            if (!tmp) {
                free(buf);
                return -1;
            }
            buf = tmp;
            cap = new_cap;
        }

        buf[len++] = (char)c;
        if (c == '\n') break;
    }

    if (len == 0 && c == EOF) {
        *lineptr = NULL;
        *n = 0;
        free(buf);
        return -1;
    }

    buf[len] = '\0';
    *lineptr = buf;
    *n = cap;

    return (ssize_t)len;
}
