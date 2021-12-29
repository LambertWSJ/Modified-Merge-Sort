#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "list.h"


typedef void (divide_f)(node_t **list, node_t *lists[], size_t *listsSize);
typedef void (merge_f)(node_t **list, node_t *lists[], size_t listsSize);


void merge_sort_iter(node_t **list, divide_f divide , merge_f merge) {
    size_t listsSize = 0;
    const size_t n = get_list_length(*list);
    node_t *lists[n];
    
    divide(list, lists, &listsSize);
    merge(list, lists, listsSize);
}

node_t *mergesort_list(node_t *head)
{
    if (!head || !head->next)
        return head;
    node_t *slow = head;
    node_t *fast;
    for (fast = head->next; fast && fast->next; fast = fast->next->next)
        slow = slow->next;
    node_t *mid = slow->next;
    slow->next = NULL;

    node_t *left = mergesort_list(head);
    node_t *right = mergesort_list(mid);
    return mergeTwoLists(left, right);
}

void mergesort(node_t **list)
{
    *list = mergesort_list(*list);
}




#endif