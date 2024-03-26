
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "data_structures.h"
//////////////////////////////////////////////////////////// 
STACK* init(int capacity){
    STACK *stack = new STACK; //create the stack
    stack->capacity = capacity; //make the stacks capacity equal to the parameter
    stack -> first = 0;
    stack->element = new pVERTEX[capacity];
    return stack; //return it
}
//////////////////////////////////////////////////////////// 
void push(STACK *stack, pVERTEX vertex){
if ((stack->capacity) == stack->first) {
    fprintf(stderr, "Size doesn't match");
    fprintf(stderr,"\n");
    return;}
stack->element[stack->first] = vertex; //add it
stack->first++;}
//////////////////////////////////////////////////////////// 
pVERTEX pop(STACK *stack){
    if (stack->first == -1){
        fprintf(stderr,"Stack empty");
        fprintf(stderr,"\n");
        return nullptr;}
    stack->first--;
    return stack->element[stack->first]; //pop it
}
//////////////////////////////////////////////////////////// 
void stackDelete(STACK *stack){
    delete[] stack->element;
    delete stack; //delete stack and its elements
}