#include <libc/stdio.h>
#include <core/thread.h>
#include <core/mutex.h>
#include <types.h>

extern uint8_t mid;
extern uint8_t orders[];
extern uint8_t recv_idx;
extern uint8_t cons_idx;
uint8_t val;
uint8_t random_job_index = 1;

static uint32_t seed = 1;

static void srand(uint32_t new_seed)
{
   seed = new_seed;
}

static uint32_t rand()
{
   uint32_t res;
   seed = seed * 1103515245 + 12345;
   res = (uint32_t)((seed / 65536) % 32768);
   return res;
}

static uint32_t rand_range(uint32_t a, uint32_t b)
{
   uint32_t res;
   if (a > b)
      printf("Invalid argument\n");

   res = a + rand() % (b - a + 1);
   return res;
}

void *receive_job1()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P1T1] mutex lock, ret=%d\n", ret);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 1;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P1T1] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P1T1] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P1T1] pok_time_get begin failed\n");
      do
      {
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P1T1] pok_time_get end failed\n");
      } while ((end - begin) < 1000000);
      // pok_thread_sleep(10000);
      // printf("[P1T1] mutex unlock, ret=%d\n", ret);
   }
}

void *receive_job2()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P1T1] mutex lock, ret=%d\n", ret);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 2;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P1T2] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P1T2] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P1T2]  pok_time_get begin failed\n");
      do
      {
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P1T2] pok_time_get end failed\n");
      } while ((end - begin) < 1000000);
      // pok_thread_sleep(10000);
      // printf("[P1T1] mutex unlock, ret=%d\n", ret);
   }
}

void *receive_job3()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P1T1] mutex lock, ret=%d\n", ret);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 3;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P1T3] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P1T3] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P1T3] pok_time_get begin failed\n");
      do
      {
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P1T3] pok_time_get end failed\n");
      } while ((end - begin) < 1000000);
      // pok_thread_sleep(10000);
      // printf("[P1T1] mutex unlock, ret=%d\n", ret);
   }
}

void *consume_job()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P1T4] mutex lock, ret=%d\n", ret);
      if (orders[cons_idx] != 0)
      {
         printf("[P1T4] consume message from P1T%d\n", orders[cons_idx]);
         orders[cons_idx] = 0;
         cons_idx = (cons_idx + 1) % 256;
      }
      else
      {
         printf("[P1T4] Buffer is empty\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P1T4] pok_time_get begin failed\n");
      do
      {
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P1T4] pok_time_get end failed\n");
      } while ((end - begin) < 1000000);
      // pok_thread_sleep(10000);
      // printf("[P1T4] mutex unlock, ret=%d\n", ret);
   }
}

void * random_job()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   uint8_t index = random_job_index;
   random_job_index += 1;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P1T1] mutex lock, ret=%d\n", ret);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = index + 3;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P1 Rand Job %d] insert message at %d\n", index, recv_idx - 1);
      }
      else
      {
         printf("[P1 Rand Job %d] Buffer is full\n", index);
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P1 Rand Job %d] pok_time_get begin failed\n", index);
      do
      {
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P1 Rand Job %d] pok_time_get end failed\n", index);
      } while ((end - begin) < 1000000);
   }
}

void *random_generator()
{
   pok_ret_t ret;
   pok_thread_attr_t tattr;
   int count = 0;
   uint32_t tid;  
   pok_time_t time;

   ret = pok_time_get(&time);
   if (ret != 0)
      printf("[Random Generator] pok_time_get failed\n");
   srand((uint32_t)time);
   while (1)
   {
      if (count >= 3){
         pok_thread_sleep(200000);
         continue;
      }
      count += 1;
      tattr.priority = rand_range(50, 60);
      tattr.time_capacity = rand_range(30, 40);
      tattr.deadline = 300;
      tattr.period = 300;
      tattr.weight = rand_range(1, 10);
      tattr.entry = random_job;
      ret = pok_thread_create(&tid, &tattr);
      printf("[P1] random_generator create random_job %d returns %d\n", random_job_index, ret);
      pok_thread_sleep(20000);
   }
}