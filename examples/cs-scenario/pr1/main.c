#include <libc/stdio.h>
#include <core/partition.h>
#include <core/thread.h>
#include <core/mutex.h>
#include <types.h>
#include "activity.h"

uint8_t mid;
uint8_t orders[256];
uint8_t recv_idx, cons_idx;

int main()
{
  uint32_t tid;
  pok_ret_t ret;
  pok_thread_attr_t tattr;
  int i, a;

  for (i = 0; i < 256; ++i){
    orders[i] = 0;
  }
  recv_idx = 0;
  cons_idx = 0;

  tattr.priority = 42;
  tattr.time_capacity = 25;
  tattr.deadline = 200;
  tattr.period = 200;
  tattr.weight = 2;
  tattr.entry = receive_job1;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] create receive_job1 returns %d\n", ret);

  tattr.priority = 42;
  tattr.time_capacity = 25;
  tattr.deadline = 200;
  tattr.period = 200;
  tattr.weight = 2;
  tattr.entry = receive_job2;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] create receive_job2 returns %d\n", ret);

  tattr.priority = 42;
  tattr.time_capacity = 25;
  tattr.deadline = 200;
  tattr.period = 200;
  tattr.weight = 2;
  tattr.entry = receive_job3;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] create receive_job3 returns %d\n", ret);

  tattr.priority = 42;
  tattr.time_capacity = 25;
  tattr.deadline = 200;
  tattr.period = 200;
  tattr.weight = 2;
  tattr.entry = consume_job;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] create consume_job returns %d\n", ret);

  tattr.priority = 42;
  tattr.time_capacity = 5;
  tattr.deadline = 200;
  tattr.period = 200;
  tattr.weight = 2;
  tattr.entry = random_generator;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] create consume_job returns %d\n", ret);

  ret = pok_mutex_create(&mid, NULL);
  printf("[P1] pok_mutex_create return=%d, mid=%d\n", ret, mid);

  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (0);
}
