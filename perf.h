#ifndef clox_perf_h

#include <stdio.h>
#include <time.h>

#define MEASURE_CPU_TIME_USED(block, name)                              \
    do                                                                  \
    {                                                                   \
        printf("== measuring execution time of block '%s' ==\n", name); \
        clock_t start, end;                                             \
        double cpu_time_used;                                           \
        start = clock();                                                \
        block;                                                          \
        end = clock();                                                  \
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;       \
        printf("== CPU time used: %f seconds ===\n", cpu_time_used);    \
    } while (false)

#endif