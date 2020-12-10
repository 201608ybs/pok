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
            printf("[P3] P3 is executing now\n");
            count = 0;
        }
        ++count;
    }
}
