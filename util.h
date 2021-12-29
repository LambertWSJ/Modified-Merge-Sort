#ifndef UTIL_H
#define UTIL_H

time_t diff(struct timespec t1, struct timespec t2)
{
    return (t2.tv_nsec - t1.tv_nsec) + (t2.tv_sec - t1.tv_sec) * 1000000000;
}

void shuffle(int *nums, size_t n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = rand() % n;
        int temp = nums[idx];
        nums[idx] = nums[i];
        nums[i] = temp;
    }
}

#endif