#include <stdio.h>
#include "list.h"
#include "merge.h"
#include "divide.h"
#include "merge_sort.h"
#include "util.h"

int main(int argc, char const *argv[])
{
    int nums[] = {5, 7, 20, 19, 32, 25, 4, 6, 3, 1, 8, 14, 12};
    size_t len = sizeof(nums) / sizeof(int);

    divide_f* divides[] = {fast_slow_divide, divide_to_single, divide_to_sorted};
    merge_f* merges[] = {head_tail_merge, interval_merge};
    int div_len = sizeof(divides) / sizeof(divide_f*);
    int mer_len = sizeof(merges) / sizeof(merge_f*);

    for (int i = 0; i < div_len; i++)
    {
        for (int j = 0; j < mer_len; j++)
        {
            shuffle(nums, len);
            node_t *list = NULL;
            list = build_list_from(nums, len);
            printf("Sort list\n");
            list_display(list);
            merge_sort_iter(&list, divides[i], merges[j]);
            list_display(list);
            list_free(&list);
        }
    }

    // all combinations
    // merge_sort_iter(&list, fast_slow_divide, head_tail_merge);
    // merge_sort_iter(&list, fast_slow_divide, interval_merge);
    // merge_sort_iter(&list, divide_to_single, head_tail_merge);
    // merge_sort_iter(&list, divide_to_single, interval_merge);
    // merge_sort_iter(&list, divide_to_sorted, head_tail_merge);
    // merge_sort_iter(&list, divide_to_sorted, interval_merge);
    return 0;
}
