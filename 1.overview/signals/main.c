#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int
main(int argc, char *argv[])
{
    int c;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal error");
    }

    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }
    
    exit(0);
}

void
sig_int(int signo)
{
    printf("interrupt\n%% ");
}