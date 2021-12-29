#include "list.h"
#include "dirent.h"

void fast_slow_divide(node_t **list, node_t *lists[], size_t *listsSize)
{
    size_t i = 0;
    int top = 0;
    node_t *stack[1000] = {NULL};
    stack[top] = *list;
    while (top >= 0)
    {
        node_t *left = stack[top--];

        if (left)
        {
            node_t *slow = left;
            for (node_t *fast = left->next; fast && fast->next; fast = fast->next->next)
                slow = slow->next;
            node_t *right = slow->next;
            slow->next = NULL;

            stack[++top] = left;
            stack[++top] = right;
        }
        else
        {
            lists[i++] = stack[top--];
        }
    }
    *listsSize = i;
}

void divide_to_single(node_t **list, node_t *lists[], size_t *listsSize)
{
    size_t i = 0;
    for (node_t *node = *list, *next; node; node = next)
    {
        next = node->next;
        node->next = NULL;
        lists[i++] = node;
    }
    *listsSize = i;
}

void divide_to_sorted(node_t **list, node_t *lists[], size_t *listsSize)
{
    size_t i = 0;
    node_t *sorted = *list;
    while (sorted)
    {
        node_t *iter = sorted;
        while (iter && iter->next)
        {
            if (iter->value < iter->next->value)
                iter = iter->next;
            else
                break;
        }
        lists[i++] = sorted;
        sorted = iter->next;
        iter->next = NULL;
    }
    *listsSize = i;
}