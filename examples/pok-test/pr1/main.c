#include <core/thread.h>
#include <core/partition.h>
#include <core/semaphore.h>
#include <types.h>
#include "activity.h"

uint8_t sid;

int main()
{
    uint8_t tid;
    pok_ret_t ret;
    pok_thread_attr_t tattr;

    tattr.priority = 43;
    tattr.time_capacity = 100000;
    tattr.deadline = 300000;
    tattr.period = 300000;
    tattr.weight = 1;
    tattr.entry = job1;

    ret = pok_thread_create(&tid, &tattr);
    printf("pok_thread_create(1) return=%d\n", ret);

    tattr.priority = 42;
    tattr.time_capacity = 100000;
    tattr.deadline = 250000;
    tattr.period = 300000;
    tattr.weight = 2;
    tattr.entry = job2;

    ret = pok_thread_create(&tid, &tattr);
    printf("pok_thread_create(2) return=%d\n", ret);

    tattr.priority = 41;
    tattr.time_capacity = 100000;
    tattr.deadline = 150000;
    tattr.period = 300000;
    tattr.weight = 4;
    tattr.entry = job3;

    ret = pok_thread_create(&tid, &tattr);
    printf("pok_thread_create(3) return=%d\n", ret);

    pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
    pok_thread_wait_infinite();

    return 0;
}