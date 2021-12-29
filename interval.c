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
    int nums[n];
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    for (int i = 0; i < epochs; i++)
    {
        shuffle(nums, n);
        node_t *list = NULL;
        list = build_list_from(nums, n);
        merge_sort_iter(&list, divide_to_sorted, interval_merge);
        list_free(&list);
    }
    return 0;
}
