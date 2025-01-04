#include <stdio.h>
#include "include/error.h"

Error lex(char *source, char **begining, char **end) {
    Error error = ok;

    if (!source || !begining || !end) {
        ERROR_PREPARE(error, ERROR_ARGUMENTS, "Can not lex empty source");
        return error;
    }
    *begining = source;
    *end = source;

    return error;
}

Error parse_expression(char *source) {
    char *begining = source;
    char *end = source;
    Error error = lex(source, &begining, &end);
    return error;
}

void print_error(Error error) {
    if (error.type == ERROR_NONE) {
        return;
    }
    printf("ERROR: ");
    switch (error.type) {
        default:
            printf("UNKNOWN: Error type...");
        break;
        case ERROR_ARGUMENTS:
            printf("INVALID ARGUMENTS");
        break;
        case ERROR_SYNTAX:
            printf("INVALID SYNTAX");
        break;
        case ERROR_TYPE:
            printf("MISMATCHED TYPES");
        break;
        case ERROR_TODO:
            printf("TODO: (not implemented)");
        break;
        case ERROR_GENERIC:
            break;
        case ERROR_NONE:
            break;
    }
    putchar('\n');
    if (error.message) {
        printf("     : %s\n", error.message);
    }
}