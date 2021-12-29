#ifndef DIVIDE_H
#define DIVIDE_H

#include "list.h"



void fast_slow_divide(node_t **list, node_t *lists[], size_t *listsSize);

void divide_to_single(node_t **list, node_t *lists[], size_t *listsSize);

void divide_to_sorted(node_t **list, node_t *lists[], size_t *listsSize);



#endif