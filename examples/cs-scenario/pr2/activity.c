#include <libc/stdio.h>
#include <core/thread.h>
#include <core/mutex.h>
#include <types.h>

extern uint8_t mid;
extern uint8_t orders[];
extern uint8_t recv_idx;
extern uint8_t cons_idx;
uint8_t val;

void *receive_job1()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 1;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P2T1] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P2T1] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P2T1] pok_time_get begin failed\n");
      do{
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P2T1] pok_time_get end failed\n");
      }while((end - begin) < 1000000);
   }
}

void *receive_job2()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 2;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P2T2] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P2T2] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P2T2]  pok_time_get begin failed\n");
      do{
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P2T2] pok_time_get end failed\n");
      }while((end - begin) < 1000000);
   }
}

void *receive_job3()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      // printf("[P2T1] mutex lock, ret=%d\n", ret);
      if (orders[recv_idx] == 0)
      {
         orders[recv_idx] = 3;
         recv_idx = (recv_idx + 1) % 256;
         printf("[P2T3] insert message at %d\n", recv_idx - 1);
      }
      else
      {
         printf("[P2T3] Buffer is full\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P2T3] pok_time_get begin failed\n");
      do{
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P2T3] pok_time_get end failed\n");
      }while((end - begin) < 1000000);
   }
}

void *consume_job()
{
   pok_ret_t ret;
   pok_time_t begin, end;
   while (1)
   {
      ret = pok_mutex_lock(mid);
      if (orders[cons_idx] != 0)
      {
         printf("[P2T4] consume message from P2T%d\n", orders[cons_idx]);
         orders[cons_idx] = 0;
         cons_idx = (cons_idx + 1) % 256;
      }
      else
      {
         printf("[P2T4] Buffer is empty\n");
      }
      ret = pok_mutex_unlock(mid);
      ret = pok_time_get(&begin);
      if (ret != 0)
         printf("[P2T4] pok_time_get begin failed\n");
      do{
         ret = pok_time_get(&end);
         if (ret < 0)
            printf("[P2T4] pok_time_get end failed\n");
      }while((end - begin) < 1000000);
   }
}