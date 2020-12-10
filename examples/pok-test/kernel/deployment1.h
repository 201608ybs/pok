#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_NEEEDS_DEBUG 1

#define POK_NEEDS_THREADS 1
#define POK_NEEDS_PARTITIONS 1
#define POK_NEEDS_SCHED 1

/* the macros added for partitions scheduling */
#define POK_NEEDS_PARTITIONS_SCHED 1
#define POK_PARTITIONS_SCHED_TYPE POK_SCHED_RR
#define POK_PARTITIONS_SCHED_TIME_SLICE 4

#define POK_CONFIG_PARTITIONS_SCHEDULER                          \
    {                                                            \
        POK_SCHED_GLOBAL_TIMESLICE, POK_SCHED_EDF, POK_SCHED_WRR \
    }

#define POK_NEEDS_TIME 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_CONSOLE 1

#define POK_CONFIG_NB_THREADS 8
#define POK_CONFIG_NB_PARTITIONS 3

#define POK_CONFIG_PARTITIONS_SIZE {120 * 1024, 120 * 1024, 120 * 1024};
#define POK_CONFIG_PROGRAM_NAME {"pr2/pr2.elf", "pr3/pr3.elf", "pr4/pr4.elf"};

#define POK_CONFIG_SCHEDULING_SLOTS \
    {                               \
        12, 14, 16                  \
    }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 42
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION \
    {                                          \
        0, 1, 2                                \
    }
#define POK_CONFIG_SCHEDULING_NBSLOTS 3

/* the macros added for partitions scheduling */
#define POK_CONFIG_PARTITIONS_PRIORITY \
    {                                  \
        43, 42, 41                     \
    }
#define POK_CONFIG_PARTITIONS_PERIOD \
    {                                \
        30, 40, 50                   \
    }
#define POK_CONFIG_PARTITIONS_DEADLINE \
    {                                  \
        30, 20, 40                     \
    }
#define POK_CONFIG_PARTITIONS_WEIGHT \
    {                                \
        1, 2, 3                      \
    }

#define POK_CONFIG_PARTITIONS_NTHREADS \
    {                                  \
        2, 2, 2                        \
    }
#endif