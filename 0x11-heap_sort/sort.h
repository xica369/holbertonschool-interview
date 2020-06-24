#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heap(int *array, size_t size_max, size_t size, size_t idx);

#endif
