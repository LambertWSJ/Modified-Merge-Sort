# Modified Merge Sort

## Divide 
* divide list to single node 
* fast-slow pointer divide list to single node 
* divide sorted list in list

## merge
* interval
* head-tail
* priority queue(TODO)

## Iterative merge sort interface

```c
merge_sort_iter(node_t **list, divide_f divide , merge_f merge)
```

divide_f: divide list function

merge_f: merge list function

example:
```c
merge_sort_iter(&list, divide_to_sorted, interval_merge);
```

## build

benchmark merge sort
```
make run
```
show merge sort example
```
make example
```

