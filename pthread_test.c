#include <stdio.h>
#include <error.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_l = PTHREAD_COND_INITIALIZER;

int i = 1;
int run(void *);

int main(int argc, char **argv)
{
    pthread_t pid1;
    pthread_t pid2;
    pthread_t pid3;
    pthread_t pid4;

    pthread_create(&pid1, NULL, (void *)run, NULL );
    printf("new thread:%u\n", (unsigned int)pid1);
    sleep(1);

    pthread_create(&pid2, NULL, (void *)run, NULL );
    printf("new thread:%u\n", (unsigned int)pid2);
    sleep(1);

    pthread_create(&pid3, NULL, (void *)run, NULL );
    printf("new thread:%u\n", (unsigned int)pid3);
    sleep(1);

    pthread_create(&pid4, NULL, (void *)run, NULL );
    printf("new thread:%u\n", (unsigned int)pid4);
    sleep(1);

    //修改
    //pthread_mutex_lock(&mutex);

    i = 2;
    pthread_cond_signal(&cond_l);
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

int run(void *s)
{
    pthread_mutex_lock(&mutex);
    //while(i == 1)
    {
        printf("线程%u进入等待状态\n", (unsigned int)pthread_self());
        pthread_cond_wait(&cond_l, &mutex);
    }
    printf("已经解开%u\n", (unsigned int)pthread_self());
    pthread_mutex_unlock(&mutex);
    i = 1;

    return ( 1);
}
