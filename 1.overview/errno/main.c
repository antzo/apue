#include "apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;

    /* UNIX standard convention. Passing the name of the program that generates the error */
    perror(argv[0]);
    exit(0);
}