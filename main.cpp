
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cfloat>
#include "util.h"
#include "heap.h"
#include "stack.h"
#include "graph.h"
int main(int argc, char **argv){
    if (argc != 4){ //error handling
        fprintf(stderr, "Usage: %s <ifile> <ofile> flag\n", argv[0]);
        return 1;
    }
    //variables
    int direction = 0;
    int flag = 2;
    char* type = argv[2];
    if (strcmp(type, "DirectedGraph") != 0 && strcmp(type, "UndirectedGraph") != 0) {
        fprintf(stderr, "Invalid type");
        fprintf(stderr, "\n");
        return 1;
    } //check if its a directed graph and pass it as an argument value
    if (strcmp(argv[3], "1") != 0 && strcmp(argv[3], "2") != 0) {
        fprintf(stderr, "Invalid execution");
        fprintf(stderr, "\n");
        return 1;
    } //error handling
    if (strcmp(type, "DirectedGraph") == 0){
        direction = 1;
    }
    if (strcmp(argv[3], "1") == 0){
        flag = 1;
    }
    //variables
    char Word[100];
    char* input = argv[1];
    int numvertex, numedges = 0;
    readInitialGraph(input, &numvertex, &numedges);
    pGRAPH graph = makeGraph(numvertex,numedges);
    Read(graph, input, direction);
    int first,last = 0;
     int first1,last1 = 0;
    pVERTEX *vertex = (pVERTEX *)malloc(numvertex * sizeof(pVERTEX));
    ////////////////////////////////////
    if (vertex == NULL) {
        fprintf(stderr, "failed to allocate");
        fprintf(stderr, "\n");
        goAway(graph);//delete 
        return 1;
    }

    // initialize each vertex for use
    for (int i = 0; i < numvertex; i++) {
        vertex[i] = (pVERTEX)malloc(sizeof(VERTEX));
        if (vertex[i] == NULL) {
            fprintf(stderr, "failed to allocate");
            for (int j = 0; j < i; j++) {
                free(vertex[j]); //delete if null
            }
            free(vertex);
            goAway(graph); //delete graph and vertex if null
            return 1;
        } //else 
        vertex[i]->index = i; //initialize
        vertex[i]->predecessor = -1; //initialize
        vertex[i]->key = DBL_MAX; // infinity
    }

    //check for commands
    while (1){
    fscanf(stdin,"%99s", Word);
        if (strcmp(Word, "SingleSource")==0){
            if(scanf("%d", &first)==1){ //make sure there is a number after 
                SingleSource(graph, vertex,first);
            }else{
                fprintf(stderr, "Warning: Invalid instruction\n");
            }
            continue;
        }
        else if (strcmp(Word, "PrintADJ")==0){
            printADJ(graph, flag);
            continue;
        }
        else if (strcmp(Word, "SinglePair")==0){
            if(scanf("%d", &first) && scanf("%d",&last)==1){ // Making Sure their are 2 numbers after the call
            SinglePair(graph, vertex, first, last);
            }else{
                fprintf(stderr, "Warning: Invalid instruction\n");
            }
            continue;
        }
        else if (strcmp(Word, "PrintPath")==0){
            if(scanf("%d", &first1) && scanf("%d",&last1)==1){ // Making Sure their are 2 numbers after the call
                if(first1 == first || last1 == last){
                PrintPath(graph, vertex, first1, last1);
                if(first1 != first && last1 != last){
                    continue;
                }
            }
            }else{
                fprintf(stderr, "Warning: Invalid instruction\n");
            }
            continue;
        }else if (strcmp(Word, "PrintLength")==0){
            if(scanf("%d", &first) && scanf("%d",&last)==1){ // Making Sure their are 2 numbers after the call
            PrintLength(vertex, first, last);
            }else{
                fprintf(stderr, "Warning: Invalid instruction\n");
            }
            continue;
        }
        else if (strcmp(Word, "Stop")==0){
            break;}
            else{
                fprintf(stderr, "Warning: Invalid instruction\n");
            }}
    for (int i = 0; i < numvertex; i++) {
        free(vertex[i]);
    } //free
    free(vertex);
    goAway(graph); //delete it
    return 0;
}