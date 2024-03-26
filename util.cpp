
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"
#include "graph.h"
//////////////////////////////////////////////////////////// 
static bool printCall = false;
void Print(HEAP* heap1, char* z){
    if(heap1 == nullptr){
        fprintf(stderr, "Error: heap is NULL");
        fprintf(stderr,"\n");
    return; //if heap is null, return error message and do nothing
    }
    char x = '1';
    if(*z == x && printCall == true){
    fprintf(stdout, "Number of Heapify calls: %d\n", heap1->count);
    heap1->count = 0; 
    printCall = false;}
fprintf(stdout,"%d" , heap1->size);//print size
fprintf(stdout,"\n");
int size = heap1 -> size; //for simpler legibility in for loop
minHeapify(heap1, 0); //from root
    for (int i = 0; i < size; i++){
        fprintf(stdout,"%f\n",heap1->A[i]->key); // iterate through heap values
    }
return;}
//////////////////////////////////////////////////////////////////////
void Write(HEAP* heap2, char* x){
    if(heap2 == nullptr){
        fprintf(stderr, "Error: heap is NULL");
        fprintf(stderr,"\n");
    return; //if heap is null, return error message and do nothing
    }
FILE* argv2 = fopen(x,"w");
    if(argv2==nullptr){ //if file is empty
        fprintf(stderr, "Error: File wasn't opened correctly");//error message
    return;}
fprintf(argv2,"%d" , heap2->size);//write size
fprintf(argv2,"\n");
int y = heap2 -> size;
minHeapify(heap2, 0);
    for (int i = 0; i < y; i++){
        fprintf(argv2,"%f\n",heap2->A[i]->key); // iterate through heap values and write them
    }
fclose(argv2); //close file
return;}
////////////////////////////////////////////////////////////
void readInitialGraph(char* x, int* vertex, int* edge){
FILE* f = fopen(x, "r");
    if (f == NULL){
        fprintf(stderr, "Error: file is NULL");
        fprintf(stderr,"\n");
    }
fscanf(f,"%d %d\n", vertex, edge);
fclose(f); //close file
return;}
//////////////////////////////////////////////////////
void Read(pGRAPH graph, char* y, int direction){
    FILE* f = fopen(y, "r"); //open it for reading
    if (f == NULL){
        fprintf(stderr, "Error: file is NULL");
        fprintf(stderr,"\n"); //if null put out this error message
    }
int edge,temp1, temp2, u, v;
double w;
fscanf(f,"%d %d\n", &temp1, &temp2); //read the vertex and edge numbers
    for (int i=0;i<graph->numEdge;i++){
        fscanf(f, "%d %d %d %lf", &edge,&u, &v, &w); //create the graph and iterate
        u --;
        v--; //decrement
        add(graph, u,v,w, direction); //add it to the graph
    }
fclose(f); //close file
return;}
///////////////////////////////////
double Extractmin(HEAP* heap5){
if(heap5 == nullptr){
        fprintf(stderr, "Error: heap is NULL");
        fprintf(stderr,"\n");
        return 0.0; //if heap is null, return error message and do nothing
    }
if(heap5->size == 0){
        fprintf(stderr, "Error: heap is empty");
        fprintf(stderr,"\n");
        return 0.0; //if heap is empty, return error message and do nothing
    }
    double temp = heap5->A[0]->key;
    heap5->A[0] = heap5->A[heap5->size -1]; //first index becomes last
    heap5->size = heap5->size - 1; //switch last index and first and decrease the size of heap
    minHeapify(heap5, 0);
    return temp;}