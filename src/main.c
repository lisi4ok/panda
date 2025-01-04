#include "error.c"
#include "parser.c"

// static void usage(const char *argv_0)
// {
//     xfprintf(stderr,
//         "Usage: %s [-a arch] [-D ident[:type]=value] [-M path] [-m symbol] [-N namespace] [-o output] [-T] [-t typedefs] [-v] input.ha...\n\n",
//         argv_0);
//     xfprintf(stderr,
//         "-a: set target architecture\n"
//         "-D: define a constant\n"
//         "-h: print this help text\n"
//         "-M: set module path prefix, to be stripped from error messages\n"
//         "-m: set symbol of hosted main function\n"
//         "-N: override namespace for module\n"
//         "-o: set output file name\n"
//         "-T: emit tests\n"
//         "-t: emit typedefs to file\n"
//         "-v: print version and exit\n");
// }

void usage(char **argv)
{
    printf("Usage: %s [parsing file]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        usage(argv);
    }

    char *path = argv[1];
    char *contents = file_contents(path);


    if (contents) {
        printf("----\n%s\n", contents);
        free(contents);
    }

    //Error error2 = lex(NULL, NULL,NULL);
    Error error = parse_expression(contents);
    print_error(error);
    // print_error(error2);

    //printf("ENV: %s\n", version);
    //printf("argc: %d\n", argc);
    //printf("argv0: %s\n", argv[1]);


    return EXIT_SUCCESS;
}
