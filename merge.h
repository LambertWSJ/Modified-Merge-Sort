#ifndef MERGE_H
#define MERGE_H

#include "list.h"

// node_t* head_tail_merge(node_t **lists, size_t listsSize);
void head_tail_merge(node_t **list, node_t *lists[], size_t listsSize);

void interval_merge(node_t **list, node_t *lists[], size_t listsSize);

#endif