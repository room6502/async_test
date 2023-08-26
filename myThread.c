/*
 * Shared Library
 *  gcc -shared -fPIC -o libMyThread.so myThread.c
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "myThread.h"


typedef struct {
    pthread_t   handle;
    myCallback  cb;
} threadProp_t;

threadProp_t    ThreadProp[5] = {0}; 



void *myAsyncThread(void* pArg)
{
    int index;
    myCallback cb = NULL;
    
    index = *(int *)pArg;
    cb = ThreadProp[index].cb;
    printf("index = %d, cb = %p\n", index, cb);
    sleep(5);
    
    cb(index);
    
    ThreadProp[index].cb = NULL;
    ThreadProp[index].handle = 0;
    
    printf("thread exit\n");
}


int myAsync(int a, myCallback cb)
{
    static int   called = 0;
    int i;
   
    if (cb == NULL)
    {
        return -1;
    }
    
    for (i=0; i<5; i++)
    {
        if (ThreadProp[i].handle == 0)
        {
            break;
        }
    }
    if (i == 5)
    {
        return -2;
    }
    
    ThreadProp[i].cb = cb;
    pthread_create(&ThreadProp[i].handle, NULL, myAsyncThread, &i);
    if (ThreadProp[i].handle == 0)
    {
        return -1;
    }
    
    printf("called = %d\n", called);
    called ++;
}

