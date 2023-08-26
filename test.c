/*
 * gcc test.c -L./ -lMyThread -lpthread -o test
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "myThread.h"


void myCB1(int a)
{
    printf("myCB1 - a = %d\n", a);
}

void myCB2(int a)
{
    printf("myCB2 - a = %d\n", a);
}


void main(int argc, char **argv)
{
    myAsync(0, myCB1);
    myAsync(0, myCB2);
    
    for (int i=0; i<10; i++)
    {
        printf("i = %d (in main.c)\n", i);
        sleep(10);
    }
}



