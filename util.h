
#ifndef _util_h
#define _util_h 1
#include <stdio.h>
#include <string.h>
#include "data_structures.h"
#include "heap.h"
void Print(HEAP* heap1, char* z);
void Write(HEAP* heap2, char* x);
void Read(pGRAPH graph, char* y, int direction);
double Extractmin(HEAP* heap5);
void readInitialGraph(char* x, int* vertex, int* edge);
#endif