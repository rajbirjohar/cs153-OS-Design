#include "types.h"
#include "user.h"
//#include "stat.h"
//#include "x86.h"
#include "spinlock.h"
//#include "defs.h"

int priorityScheduler(void);

int main(int argc, char *argv[]){
	//printlock_init();
    printf(1, "\nThis program tests lab #2.\n");
    priorityScheduler();
    return 0;
}

//void printlock_init(void){
	//strcopy(lock.name, "printlock");
	//lock.ticket = 0;
	//lock.tun = 0;
//}

int priorityScheduler(void){
    int pid[6];
    int i,j,k;
    printf(1,"\nThis lab converts round robin to priority scheduler with a system call. "
             "\nThe priorities range form 0-31 with 0 being the highest priority.\n");
    set_prior(0);
    for (i = 0; i <  6; i++){
        pid[i] = fork();
        if (pid[i] > 0 ) {
            continue;}
        else if ( pid[i] == 0){
            set_prior(30 - 5 * i);
            for (j=0;j<50000;j++){
				asm("nop");
                for(k=0;k<1000;k++){
                    asm("nop");
                }
            }
            printf(1,"\nChild# %d with priority %d completed. Test 1.\n",getpid(),30 - 5 * i);
            exitS(1);
        }else{printf(2,"\nError\n");}
    }
    if(pid > 0){
        for (i = 0; i <  6; i++){
            wait();
        }
        printf(1,"If process with higher priority finished first then it is correct.");
    }
    //wait();
    //exit();
    return 0;
}
