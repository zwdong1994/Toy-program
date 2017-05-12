#include <stdio.h>
#include <error.h>
#include <pthread.h>
#include "pt.h"
#include <unistd.h>


int i = 1;
void* run(void *);

int main(int argc, char **argv)
{
    Mutex *mu = Mutex::Get_mutex();
    CondVar *cv = CondVar::Get_cond(mu);
    pthread_t pid1;
    pthread_t pid2;
    pthread_t pid3;
    pthread_t pid4;

    pthread_create(&pid1, NULL, run, NULL );
    printf("new thread:%u\n", (unsigned int)pid1);
    sleep(1);

    pthread_create(&pid2, NULL, run, NULL );
    printf("new thread:%u\n", (unsigned int)pid2);
    sleep(1);

    pthread_create(&pid3, NULL, run, NULL );
    printf("new thread:%u\n", (unsigned int)pid3);
    sleep(1);

    pthread_create(&pid4, NULL, run, NULL );
    printf("new thread:%u\n", (unsigned int)pid4);
    sleep(1);

    //修改
    //pthread_mutex_lock(&mutex);

    i = 2;
    cv -> signal();
    printf("release signal\n");
    sleep(1);

/*    i = 2;
    pthread_cond_signal(&cond_l);
    printf("release signal\n");
    sleep(1);

    i = 2;
    pthread_cond_signal(&cond_l);
    printf("release signal\n");
    sleep(1);

    i = 2;
    pthread_cond_signal(&cond_l);
    printf("release signal\n");
    sleep(1);*/

    pthread_join(pid1, NULL );
    pthread_join(pid2, NULL );
    pthread_join(pid3, NULL );
    pthread_join(pid4, NULL );
    return 0;
}

void* run(void *s)
{
    Mutex *mu = Mutex::Get_mutex();
    CondVar *cv = CondVar::Get_cond(mu);
    mu -> lock();
    //while(i == 1)
    {
        printf("线程%u进入等待状态\n", (unsigned int)pthread_self());
        cv -> wait();
    }
    printf("已经解开%u\n", (unsigned int)pthread_self());
    mu -> unlock();
    i = 1;

    return ((void *) 1);
}
