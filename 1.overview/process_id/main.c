#include "apue.h"

int
main(int argc, char *argv[])
{
    printf("process ID: %ld\n", (long)getpid());
    exit(0);
}