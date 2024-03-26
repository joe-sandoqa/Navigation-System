
#ifndef _heap_h
#define _heap_h_ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
HEAP* Init(int capacity);
void Insert(HEAP* heap4, ELEMENT* key1);
void DecreaseKey(HEAP* heap6,  int index, double newkey);
void minHeapify(HEAP* heap, int count);
#endif