#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
    int priorityScheduler(void);
    printf(1, "\nThis program tests lab #2.\n");
    priorityScheduler();
    return 0;
}

int priorityScheduler(void){
    int pid[5];
    int priority[5] = {22, 13, 18, 6, 31};
    int i,j,k;
    printf(1,"\nThis lab converts round robin to priority scheduler with a system call. "
             "\nThe priorities range form 0-31 with 0 being the highest priority.\n");
    set_prior(0);
    for (i = 0; i <  5; i++){
        pid[i] = fork();
        if (pid[i] > 0 ) {
            continue;}
        else if ( pid[i] == 0){
            set_prior(priority[i]);
            for (j=0;j<50000;j++){
				asm("nop");
                for(k=0;k<1000;k++){
                    asm("nop");
                }
            }
            printf(1, "\nChild# %d with priority %d completed. Test 2.\n",getpid(),priority[i]);
            exitS(1);
        }else{printf(2,"\nError\n");}
    }
    if(pid > 0){
        for (i = 0; i <  5; i++){
            wait();
        }
        printf(1,"If process with higher priority finished first then it is correct.");
    }
    //exit();
    return 0;
}
