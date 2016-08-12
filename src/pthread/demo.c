#include <pthread.h>
#include <stdio.h>
#include <string.h>

int g_Flag = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread1(void *);
void *thread2(void *);

int main(int argc, char *argv[])
{
    puts("enter main");
    pthread_t tid1, tid2;
    int rc1 = 0, rc2 = 0;

    rc2 = pthread_create(&tid2, NULL, thread2, NULL);
    if (rc2 != 0)
        printf("%s: %s\n", __func__, strerror(rc2));

    rc1 = pthread_create(&tid1, NULL, thread1, &tid2);
    if (rc1 != 0)
        printf("%s: %s\n", __func__, strerror(rc1));
//    sleep(1);

    pthread_cond_wait(&cond, &mutex);
    puts("leave main");
    return 0;
}

void *thread1(void *arg)
{
    printf("enter thread1\n");
    printf("this is thread1, g_Flag: %d, thread id is %u\n", g_Flag,
            (unsigned int)pthread_self());
    if (pthread_mutex_lock(&mutex) != 0)
        fprintf(stderr, "lock error\n");
    if (g_Flag == 2)
        pthread_cond_signal(&cond);
    g_Flag = 1;
    printf("this is thread1, g_Flag: %d, thread id is %u\n", g_Flag,
            (unsigned int)pthread_self());
    pthread_mutex_unlock(&mutex);
    pthread_join(*(pthread_t *)arg, NULL);
    printf("leave thread1\n");
    return NULL;
}

void *thread2(void *arg)
{
    printf("enter thread2\n");
    printf("this is thread2, g_Flag: %d, thread id is %u\n", g_Flag,
            (unsigned int)pthread_self());
    if (pthread_mutex_lock(&mutex) != 0)
        fprintf(stderr, "lock error\n");
    if (g_Flag == 1)
        pthread_cond_signal(&cond);
    g_Flag = 2;
    printf("this is thread2, g_Flag: %d, thread id is %u\n", g_Flag,
            (unsigned int)pthread_self());
    pthread_mutex_unlock(&mutex);
    printf("leave thread2\n");
    return NULL;
}

