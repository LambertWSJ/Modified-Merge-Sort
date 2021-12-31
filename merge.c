#include "merge.h"

void head_tail_merge(node_t **list, node_t *lists[], size_t listsSize)
{
    while (listsSize > 1)
    {
        for (int i = 0, j = listsSize - 1; i < j; i++, j--)
            lists[i] = mergeTwoLists(lists[i], lists[j]);
        listsSize = (listsSize + 1) / 2;
    }
    *list = lists[0];
}

void interval_merge(node_t **list, node_t *lists[], size_t listsSize)
{
    for (int interval = 1; interval < listsSize; interval *= 2)
        for (int i = 0; i + interval < listsSize; i += interval * 2)
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);

    *list = lists[0];
}

static node_t* merge_lists(node_t **lists, int low, int high) {
    if(low > high)
        return NULL;
    if(low == high)
        return lists[low];

    int mid = (low + high) / 2;
    node_t *left = merge_lists(lists, low, mid);
    node_t *right = merge_lists(lists, mid + 1, high);

    return mergeTwoLists(left, right);
}

void divide_and_conquer(node_t **list, node_t *lists[], size_t listsSize) {
    *list = merge_lists(lists, 0, listsSize - 1);
}