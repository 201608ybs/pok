#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_NEEDS_TIME 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_CONSOLE 1
#define POK_NEEDS_THREADS 1
#define POK_NEEDS_PARTITIONS 1
#define POK_NEEDS_LOCKOBJECTS 1

#define POK_CONFIG_NB_THREADS 9
#define POK_NEEDS_SCHED 1
#define POK_CONFIG_PARTITIONS_NTHREADS \
   {                                   \
      5, 2                             \
   }
#define POK_CONFIG_PARTITIONS_SCHEDULER         \
   {                                            \
      POK_SCHED_GLOBAL_TIMESLICE, POK_SCHED_EDF \
   }

#define POK_NEEDS_THREAD_SUSPEND 1
#define POK_NEEDS_THREAD_SLEEP 1

#define POK_CONFIG_NB_PARTITIONS 2
#define POK_CONFIG_PARTITIONS_SIZE {120 * 1024, 120 * 1024};
#define POK_CONFIG_PROGRAM_NAME {"pr1/pr1.elf", "pr2/pr2.elf"};

#define POK_NEEDS_PARTITIONS_SCHED 1
#define POK_PARTITIONS_SCHED_TYPE POK_SCHED_RR
#define POK_PARTITIONS_SCHED_TIME_SLICE 4

#define POK_CONFIG_NB_LOCKOBJECTS 1
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS \
   {                                       \
      1, 0                                 \
   }

#define POK_CONFIG_SCHEDULING_SLOTS \
   {                                \
      10, 10                        \
   }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 20
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION \
   {                                           \
      0, 1                                     \
   }
#define POK_CONFIG_SCHEDULING_NBSLOTS 2

/* the macros added for partitions scheduling */
#define POK_CONFIG_PARTITIONS_PRIORITY \
   {                                   \
      42, 42                           \
   }
#define POK_CONFIG_PARTITIONS_PERIOD \
   {                                 \
      20, 20                         \
   }
#define POK_CONFIG_PARTITIONS_DEADLINE \
   {                                   \
      30, 30                           \
   }
#define POK_CONFIG_PARTITIONS_WEIGHT \
   {                                 \
      4, 4                           \
   }

#endif