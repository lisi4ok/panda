#ifndef ERROR_H
#define ERROR_H

typedef struct Error {
    enum {
        ERROR_NONE = 0,
        ERROR_ARGUMENTS,
        ERROR_SYNTAX,
        ERROR_TYPE,
        ERROR_GENERIC,
        ERROR_TODO,
    } type;
    char *message;
} Error;

#define ERROR_CREATE(n, type, message) \
    Error (n) =  { (type), (message) }

#define ERROR_PREPARE(n, t, msg) \
    (n).type = (t); \
    (n).message = (msg);

Error ok = {
    ERROR_NONE,
    NULL,
};

#endif