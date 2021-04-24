#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int waitPid(void);

    printf(1, "\n This program tests the correctness of lab#1\n");

    if (atoi(argv[1]) == 1)
        waitPid();
    else
        printf(1, "\n Type \"lab1test 1\" to test waitpid. \n");

    // End of test
    exitS(0);
    return 0;
}

int waitPid(void){

    int ret_pid, exit_status;
    int i;
    int pid_a[2]={0, 0};

    printf(1, "\n  Part c) testing waitpid(int pid, int* status, int options):\n");

    for (i = 0; i <2; i++) {
        pid_a[i] = fork();
        if (pid_a[i] == 0) { // only the child executed this code
            printf(1, "\n Child pid# %d exiting with status %d\n", getpid(), getpid() + 1);
            exitS(getpid() + 1);
        }
    }

    sleep(5);
    printf(1, "\n Parent: Waiting for child pid# %d\n",pid_a[0]);
    ret_pid = waitpid(pid_a[0], &exit_status, 0);
    printf(1, "\n Parent: Child pid# %d has exited with status %d\n",ret_pid, exit_status);

    sleep(5);
    printf(1, "\n Parent: Waiting for child pid# %d\n",pid_a[1]);
    ret_pid = waitpid(pid_a[1], &exit_status, 0);
    printf(1, "\n Parent: Child pid# %d has exited with status %d\n",ret_pid, exit_status);

    return 0;
}