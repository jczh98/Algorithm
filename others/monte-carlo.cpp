#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <pthread.h>
#define eps 10000000
#define THREAD_COUNTS 8
using namespace std;

const double rpi=3.1415926;
double x,y,pi,calpi=(1<<20);
pthread_t *threads;
pthread_mutex_t mutex;

void *Cal(void *a)
{
    int vaild=0;
    for(int i=1;i<=eps;i++)
    {
        x=2.0*rand()/(RAND_MAX+1.0)-1.0;
        y=2.0*rand()/(RAND_MAX+1.0)-1.0;
        if(x*x+y*y<=1)vaild++;
    }
    pi=4.0*vaild/eps;
    if(fabs(pi-rpi)<fabs(calpi-rpi))calpi=pi;
}

int main()
{
    srand(time(0));
    threads=(pthread_t*)malloc(THREAD_COUNTS*sizeof(pthread_t));
    pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<THREAD_COUNTS;i++)
    {
        pthread_create(&threads[i],NULL,Cal,(void *)i);
    }
    void **get_return;
    for(int i=0;i<THREAD_COUNTS;i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("%.4lf\n",calpi);
    return 0;
}
