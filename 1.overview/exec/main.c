#include "apue.h"
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% "); /* print char % */

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
            /* Replace last char (newline) with null, because execlp want a NULL-terminated argument */
        }

        /* Create a new process, which is a copy of the caller, and returns the PID of the child, forked process */
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        }

        /* The child process calls execlp to execute the new program */
        if (pid == 0) {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        /* Parent process waits for child process (execlp) to finish. Blocking call. 
        This is done by specifying the pid to wait for */

        /* status is saved into our int variable. We can use it to determine how the child process ended */
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }

        printf("%% ");
    }
    exit(0);
}