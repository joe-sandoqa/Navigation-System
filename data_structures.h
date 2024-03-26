
#ifndef _data_structures_h
#define _data_structures_h 1
struct TAG_NODE;
struct TAG_VERTEX;
typedef struct TAG_NODE* pNODE;
typedef struct TAG_VERTEX* pVERTEX;
typedef struct TAG_GRAPH {
    int numVertex, numEdge;
    pNODE* adjList;
} GRAPH, *pGRAPH;
typedef struct TAG_ELEMENT {
    double key;
    // other fields as you see fit
}ELEMENT, *pELEMENT;
typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */
    ELEMENT** A; /* array of pointers to ELEMENT */
    int count; //number of heapify calls
    
}HEAP;
typedef struct TAG_NODE{
    int index, u, v;
    double w; //weight
    pNODE next;
}NODE;
typedef struct TAG_VERTEX{
    int index, predecessor, position;
    char color;
    double key;
    ELEMENT* heap;
}VERTEX;
typedef struct TAG_STACK {
    int capacity;    
    int first;        
    pVERTEX* element;
} STACK;
#endif