#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_NEEEDS_DEBUG 1

#define POK_NEEDS_THREADS 1
#define POK_NEEDS_PARTITIONS 1
#define POK_NEEDS_SCHED 1
#define POK_CONFIG_PARTITIONS_SCHEDULER \
    {                                   \
        POK_SCHED_WRR     \
    }
/* the macros added for partitions scheduling */
// #define POK_NEEDS_PARTITIONS_SCHED 1
// #define POK_NEEDS_SCHED_WRR 1
// #define POK_PARTITIONS_SCHED_TYPE POK_SCHED_RR
// #define POK_PARTITIONS_SCHED_TIME_SLICE 20
// #define POK_CONFIG_PARTITIONS_SCHEDULER {POK_SCHED_GLOBAL_TIMESLICE, POK_SCHED_GLOBAL_TIMESLICE}

#define POK_NEEDS_TIME 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_CONSOLE 1
// #define POK_NEEDS_LOCKOBJECTS 1

#define POK_CONFIG_NB_THREADS 6
// #define POK_CONFIG_NB_LOCKOBJECTS   1
#define POK_CONFIG_NB_PARTITIONS 1

#define POK_CONFIG_PARTITIONS_SIZE {240 * 1024};
#define POK_CONFIG_PROGRAM_NAME {"pr1/pr1.elf"};

#define POK_CONFIG_SCHEDULING_SLOTS \
    {                               \
        1000000000                  \
    }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 1000000000
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION \
    {                                          \
        0                                      \
    }
#define POK_CONFIG_SCHEDULING_NBSLOTS 1

// #define POK_CONFIG_SCHEDULING_SLOTS {1000000000, 1000000000}
// #define POK_CONFIG_SCHEDULING_MAJOR_FRAME 2000000000
// #define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION {0,1}
// #define POK_CONFIG_SCHEDULING_NBSLOTS 2

/* the macros added for partitions scheduling */
// #define POK_CONFIG_PARTITIONS_PRIORITY {42, 42}
// #define POK_CONFIG_PARTITIONS_PERIOD {2000000000, 2000000000}
// #define POK_CONFIG_PARTITIONS_DEADLINE {2000000000, 2000000000}
// #define POK_CONFIG_PARTITIONS_WEIGHT {100, 100}

// #define POK_NEEDS_THREAD_SUSPEND 1
// #define POK_NEEDS_THREAD_SLEEP 1

#define POK_CONFIG_PARTITIONS_NTHREADS \
    {                                  \
        4                              \
    }

// typedef enum
// {
//     pok_part_identifier_pr1 = 0,
// } pok_part_identifiers_t;

// typedef enum
// {
//     pok_part_id_pr1 = 0,
// } pok_part_id_t;

// typedef enum
// {
//     pok_nodes_node1 = 0
// } pok_node_id_t;

#endif