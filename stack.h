
#ifndef _stack_h
#define _stack_h_ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
STACK* init(int capacity);
void stackDelete(STACK *stack);
void push(STACK *stack, pVERTEX vertex);
pVERTEX pop(STACK *stack);
#endif