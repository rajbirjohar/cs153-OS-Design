//#include "types.h"
//#include "user.h"
//
//int main(int argc, char *argv[])
//{
//    int waitPid(void);
//
//    printf(1, "\n This program tests the correctness of lab#1\n");
//
//    if (atoi(argv[1]) == 1)
//        waitPid();
//    else
//        printf(1, "\n Type \"lab1test 1\" to test waitpid. \n");
//
//    // End of test
//    exitS(0);
//    return 0;
//}
//
//int waitPid(void){
//
//    int ret_pid, exit_status;
//    int i;
//    int pid_a[2]={0, 0};
//
//    printf(1, "\n  Part c) testing waitpid(int pid, int* status, int options):\n");
//
//    for (i = 0; i <2; i++) {
//        pid_a[i] = fork();
//        if (pid_a[i] == 0) { // only the child executed this code
//            printf(1, "\n Child pid# %d expected to exit with status %d\n", getpid(), getpid());
//            exitS(getpid());
//        }
//    }
//
//    sleep(5);
//    printf(1, "\n Parent: Waiting for child pid# %d\n",pid_a[0]);
//    ret_pid = waitpid(pid_a[0], &exit_status, 0);
//    printf(1, "\n Parent: Child pid# %d has exited with status %d\n",ret_pid, exit_status);
//
//    sleep(5);
//    printf(1, "\n Parent: Waiting for child pid# %d\n",pid_a[1]);
//    ret_pid = waitpid(pid_a[1], &exit_status, 0);
//    printf(1, "\n Parent: Child pid# %d has exited with status %d\n",ret_pid, exit_status);
//
//    return 0;
//}

//#include <pthread.h>
//#include <stdio.h>
//
//#define len 8
//
//int sum = 0;
//
//void *array_sum(void *arg)
//{
//    int i;
//    int *val = (int *)arg;
//    for(i=0; i<2; i++)
//    {
//        sum += val[i];
//    }
//    pthread_exit(0);
//}
//
//int main() {
//    int i;
//    int j;
//    pthread_t thread[2];
//    int A[2][2] = {{1,2},{3,4}};
//
//    for(i=0; i<2; i++) {
//        pthread_create(&thread[i], NULL, array_sum, A[i]);
//    }
//
//    for(j=0; j<2; j++) {
//        pthread_join(thread[j], NULL);
//    }
//
//    printf("\nSum of arrays [1,2] and [3,4] is %d\n", sum);
//
//    return 0;
//}
//
//#include <stdio.h>
//#include <pthread.h>
//#include <semaphore.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <time.h>
//sem_t semaphore;
//int gameOver = 0;
//void* player1_thread() {
//    sem_wait(&semaphore);
//    if(gameOver != 1) {
//        if (rand() % 5 == 0) {
//            printf("Player 1 drops the ball.\n");
//            gameOver = 1;
//        } else {
//            printf("Player 1 hits it back to Player 2.\n");
//        }
//    }
//    sem_post(&semaphore);
//    return NULL;
//}
//void* player2_thread() {
//    sem_wait(&semaphore);
//    if(gameOver !=1) {
//        if (rand() % 5 == 0) {
//            printf("Player 2 drops the ball.\n");
//            gameOver = 1;
//        } else {
//            printf("Player 2 hits it back to Player 1.\n");
//        }
//    }
//    sem_post(&semaphore);
//
//    return NULL;
//}
//int main() {
//    pthread_t thread_1, thread_2;
//
//    sem_init(&semaphore,0, 1);
//    printf("Player 1 serves.\n");
//    srand(time(0));
//
//    while(gameOver == 0){
//        pthread_create(&thread_2, NULL, &player2_thread,NULL);
//        pthread_create(&thread_1, NULL, &player1_thread,NULL);
//
//    }
//
//    pthread_join(thread_1, NULL);
//    pthread_join(thread_2, NULL);
//    sem_destroy(&semaphore);
//    return 0;
//}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 5;

sem_t mutex;
sem_t barrier;

int i;

void *order(void *arg){

    sem_wait(&mutex);
    count--;
    printf("Person %d has entered.\n", i);
    sem_post(&mutex);

    if(count == 0){
        sem_post(&barrier);
    }

    pthread_exit(0);
}

int main(){
    pthread_t thread[5];

    sem_init(&mutex, 0, 1);
    sem_init(&barrier, 0, 0);

    for(i = 1; i < 6; i++){
        pthread_create(&thread[i], NULL, order, NULL);

    }
    printf("All persons have arrived. Ordering now.\n");
    return 0;
}