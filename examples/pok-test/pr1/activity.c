#include <libc/stdio.h>
#include <core/thread.h>
#include <core/semaphore.h>
#include <types.h>

extern uint8_t sid;
uint8_t val;

void *job1()
{
    pok_ret_t ret;
    int count = 0;
    while (1)
    {   
        if (count >= 10000){
            printf("[T1] T1 is executing now\n");
            count = 0;
        }
        ++count;
    }
}

void *job2()
{
    pok_ret_t ret;
    int count = 0;
    while (1)
    {   
        if (count >= 10000){
            printf("[T2] T2 is executing now\n");
            count = 0;
        }
        ++count;
    }
}

void *job3()
{
    pok_ret_t ret;
    int count = 0;
    while (1)
    {   
        if (count >= 10000){
            printf("[T3] T3 is executing now\n");
            count = 0;
        }
        ++count;
    }
}
