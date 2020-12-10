#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#define POK_NEEEDS_DEBUG 1

#define POK_NEEDS_THREADS 1
#define POK_NEEDS_PARTITIONS 1
#define POK_NEEDS_SCHED 1
#define POK_NEEDS_LOCKOBJECTS 1
#define POK_NEEDS_THREAD_SUSPEND 1
#define POK_NEEDS_THREAD_SLEEP 1
#define POK_NEEDS_GETTICK 1

/* the macros added for partitions scheduling */
#define POK_NEEDS_PARTITIONS_SCHED 1
#define POK_PARTITIONS_SCHED_TYPE POK_SCHED_RR
#define POK_PARTITIONS_SCHED_TIME_SLICE 10

#define POK_CONFIG_PARTITIONS_SCHEDULER           \
    {                                             \
        POK_SCHED_GLOBAL_TIMESLICE, POK_SCHED_EDF \
    }
#define POK_CONFIG_PARTITIONS_NTHREADS \
    {                                  \
        5, 5                           \
    }

#define POK_NEEDS_TIME 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_CONSOLE 1

#define POK_CONFIG_NB_THREADS 12
#define POK_CONFIG_NB_PARTITIONS 2

#define POK_CONFIG_PARTITIONS_SIZE {120 * 1024, 120 * 1024};
#define POK_CONFIG_PROGRAM_NAME {"pr1/pr1.elf", "pr2/pr2.elf"};

#define POK_CONFIG_SCHEDULING_SLOTS \
    {                               \
        100, 100                    \
    }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 200
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION \
    {                                          \
        0, 1,                                  \
    }
#define POK_CONFIG_SCHEDULING_NBSLOTS 2

/* the macros added for partitions scheduling */
#define POK_CONFIG_PARTITIONS_PRIORITY \
    {                                  \
        42, 42                         \
    }
#define POK_CONFIG_PARTITIONS_PERIOD \
    {                                \
        180, 180                     \
    }
#define POK_CONFIG_PARTITIONS_DEADLINE \
    {                                  \
        300, 300                       \
    }
#define POK_CONFIG_PARTITIONS_WEIGHT \
    {                                \
        1, 1                         \
    }

#define POK_CONFIG_NB_LOCKOBJECTS 2
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS \
    {                                      \
        1, 1                               \
    }

typedef enum
{
    pok_part_identifier_pr1 = 0,
    pok_part_identifier_pr2 = 1
} pok_part_identifiers_t;

typedef enum
{
    pok_part_id_pr1 = 0,
    pok_part_id_pr2 = 1
} pok_part_id_t;

typedef enum
{
    pok_nodes_node1 = 0
} pok_node_id_t;
#endif