#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
    int priorityScheduler(void);
    printf(1, "\nThis program tests lab #2.\n");
    priorityScheduler();
    return 0;
}

int priorityScheduler(void){
    int pid;
    int i,j,k;
    printf(1,"\nThis lab converts round robin to priority scheduler with a system call. "
             "\nThe priorities range form 0-31 with 0 being the highest priority.\n");
    set_prior(0);
    for (i = 0; i <  6; i++){
        pid = fork();
        if (pid > 0 ) {
            continue;}
        else if ( pid == 0){
            set_prior(30 - 5 * i);
            for (j=0;j<50000;j++){
                for(k=0;k<1000;k++){
                    asm("nop");
                }
            }
            printf(1, "\nChild# %d with priority %d completed.\n",getpid(),30 - 5 * i);
            exit();
        }else{printf(2,"\nError\n");}
    }
    if(pid > 0){
        for (i = 0; i <  6; i++){
            wait();
        }
    }
    exit();
    return 0;
}