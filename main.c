#include <stdio.h>
#include <time.h>
#include "list.h"
#include "merge.h"
#include "divide.h"
#include "merge_sort.h"
#include "util.h"

int main(int argc, char const *argv[])
{

    const int n = 30000;
    const int epochs = 500;
    int interval = epochs / 10;
    int nums[n];
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    struct timespec start, end;
    const int sort_len = 3;
    time_t measures[epochs][sort_len];
    node_t *lists[sort_len];

    for (int i = 0; i < epochs; i++)
    {
        shuffle(nums, n);
        lists[0] = build_list_from(nums, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        mergesort(&lists[0]);
        clock_gettime(CLOCK_MONOTONIC, &end);
        measures[i][0] = diff(start, end);
        

        lists[1] = build_list_from(nums, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        merge_sort_iter(&lists[1], divide_to_sorted, head_tail_merge);
        clock_gettime(CLOCK_MONOTONIC, &end);
        measures[i][1] = diff(start, end);
        
        
        lists[2] = build_list_from(nums, n);
        clock_gettime(CLOCK_MONOTONIC, &start);
        merge_sort_iter(&lists[2], divide_to_sorted, interval_merge);
        clock_gettime(CLOCK_MONOTONIC, &end);
        measures[i][2] = diff(start, end);

        list_free(&lists[0]);
        list_free(&lists[1]);
        list_free(&lists[2]);

        if ((i + 1) % interval == 0)
            printf("Benchmark %-3d%%\n", 100 * (i + 1) / epochs);
    }
    FILE *file = fopen("benchmark.txt", "w+");
    for (size_t j = 0; j < epochs; j++)
    {
        for (size_t i = 0; i < sort_len; i++)
        {
            char *token = i == sort_len - 1 ? j == epochs - 1 ? "" : "\n" : "\t";
            fprintf(file, "%ld%s", measures[j][i], token);
        }
    }
    return 0;
}
