#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "list.h"
#include "merge.h"
#include "divide.h"
#include "merge_sort.h"
#include "util.h"

int main(int argc, char const *argv[])
{
    const int n = 100000;
    const int epochs = 1000;
    int interval = epochs / 10;
    int nums[n];

    struct timespec start, end;
    divide_f *divides[] = {
        fast_slow_divide,
        divide_to_single,
        divide_to_sorted
    };
    // merge_f *merges[] = {
    //     head_tail_merge,
    //     interval_merge,
    //     divide_and_conquer,
    // };

    const int sort_len = sizeof(divides) / sizeof(divide_f *);
    // const int sort_len = sizeof(merges) / sizeof(merge_f *);
    time_t measures[epochs][sort_len];
    node_t *lists[sort_len];

    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    for (int i = 0; i < epochs; i++)
    {
        shuffle(nums, n);

        for (int j = 0; j < sort_len; j++)
        {
            lists[j] = NULL;
            lists[j] = build_list_from(nums, n);
            // lists[j] = reverse(lists[j]);
        }

        for (size_t j = 0; j < sort_len; j++)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            merge_sort_iter(&lists[j], divides[j], interval_merge);
            // merge_sort_iter(&lists[j], divide_to_single, merges[j]);
            clock_gettime(CLOCK_MONOTONIC, &end);
            assert(list_is_ordered(lists[j]));
            measures[i][j] = diff(start, end);
        }
        for (size_t j = 0; j < sort_len; j++)
            list_free(&lists[j]);

        if ((i + 1) % interval == 0)
            printf("Benchmark %-3d%%\n", 100 * (i + 1) / epochs);
    }

    FILE *file = fopen("./data/benchmark.txt", "w+");
    for (size_t i = 0; i < epochs; i++)
    {
        for (size_t j = 0; j < sort_len; j++)
        {
            char *token = j == sort_len - 1 ? j == epochs - 1 ? "" : "\n" : "\t";
            fprintf(file, "%ld%s", measures[i][j], token);
        }
    }
    return 0;
}
