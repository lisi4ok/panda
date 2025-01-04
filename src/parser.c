#include <stdio.h>
#include <stdlib.h>

long file_size(FILE *file) {
    if (!file) {
        return 0;
    }
    fpos_t original = 0;

    if (fgetpos(file, &original) != 0) {
        printf("fgetpos() failed: %i \n", errno);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long output = ftell(file);

    if (fsetpos(file, &original) != 0) {
        printf("fsetpos() failed: %i \n", errno);
        return 0;
    }

    return output;
}

char *file_contents(char *path)
{
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Error opening file: %s\n", path);
        return NULL;
    }

    long size = file_size(file);
    char *contents = malloc(size + 1);
    char *writed = contents;
    size_t bytes = 0;
    while (bytes < size) {
        size_t i = fread(writed, 1, size - bytes, file);

        if (ferror(file)) {
            printf("Error reading file: %i\n", errno);
            return NULL;
        }
        bytes += i;
        writed += i;

        if (feof(file)) {
            break;
        }
    }
    contents[bytes] = '\0';
    return contents;
}