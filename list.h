#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct __node
{
    int value;
    struct __node *next;
} node_t;


void list_add_node_t(node_t **list, node_t *node_t);

void list_concat(node_t **left, node_t *right);

node_t *mergeTwoLists(node_t *left, node_t *right);

node_t* build_list_from(int *nums, size_t len);

node_t* reverse(node_t *list);

bool list_is_ordered(node_t *list);

void list_display(node_t *list);

void list_free(node_t **list);

int get_list_length(node_t *list);

void shuffle_list(node_t **list);

#endif