#include "list.h"


node_t *mergeTwoLists(node_t *left, node_t *right)
{
    node_t *result = NULL;
    node_t **indir = &result;

    for (node_t **node = NULL; left && right; *node = (*node)->next)
    {
        node = left->value < right->value ? &left : &right;
        *indir = *node;
        indir = &(*indir)->next;
    }
    *indir = left ? left : right;
    return result;
}


node_t* build_list_from(int *nums, size_t len) {
    node_t *result = NULL;
    node_t **indir = &result;

    for(int i = 0; i < len; i++) {
        node_t *node = (node_t*)malloc(sizeof(node_t));
        node->next = NULL;
        node->value = nums[i];
        *indir = node;
        indir = &(*indir)->next;
    }
    return result;
}

node_t* reverse(node_t *list) {
    node_t *prev = NULL;
    node_t *cur = list;
    while(cur) {
        node_t *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void list_free(node_t **list)
{
    node_t *cur = *list, *next = NULL;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
}


bool list_is_ordered(node_t *list)
{
    bool first = true;
    int value;
    while (list)
    {
        if (first)
        {
            value = list->value;
            first = false;
        }
        else
        {
            if (list->value < value)
                return false;
            value = list->value;
        }
        list = list->next;
    }
    return true;
}


void list_display(node_t *list)
{
    printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
    while (list)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}

int get_list_length(node_t *list)
{
    int n = 0;
    for(node_t *itr = list; itr; itr = itr->next)
        n++;
    return n;
}

