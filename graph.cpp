
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "stack.h"
#include "heap.h"
#include "util.h"
#include <cfloat>
#include <vector>
//////////////////////////////////////////////////////////// 
pGRAPH makeGraph(int numVertices, int numEdges) {
    pGRAPH graph = (pGRAPH)malloc(sizeof(GRAPH)); //create a graph 
    graph->numVertex = numVertices;
    graph->numEdge = numEdges; //put the parameterized vertex and edge to this graphs 
    graph->adjList = (pNODE*)malloc(numVertices * sizeof(pNODE)); //create the adjacent list
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL; //initialize all to NULL
    }
    return graph;}
//////////////////////////////////////////////////////////// 
void add(pGRAPH graph, int u, int v, double w, int direction) {
    pNODE node = (pNODE)malloc(sizeof(NODE)); //create the node
    node->w = w;
    node->v = v;
    node->u = u; //set its parameterized feature to the nodes
    node->next = graph->adjList[u];
    graph->adjList[u] = node;//set its parameterized feature to the nodes
    if (direction == 0) { //for undirected
        pNODE Node = (pNODE)malloc(sizeof(NODE));
            Node->w = w;
            Node->v = u ;
            Node->u = v;
            Node->next = graph->adjList[v];
            graph->adjList[v] = Node;}
    return;}
//////////////////////////////////////////////////////////// 
void PrintLength(pVERTEX* vertex, int sourceV, int final) {
    if (vertex[final - 1]->predecessor == -1|| vertex[final - 1]->key == DBL_MAX) {
        fprintf(stdout, "There is no path from %d to %d.\n", sourceV, final);
        return;} 
    fprintf(stdout, "The length of the shortest path from %d to %d is:     %.2f\n", sourceV, final, vertex[final-1]->key);
    return;}
//////////////////////////////////////////////////////////// 
void printADJ(pGRAPH graph, int flag) {
    for (int i = 0; i < graph->numVertex; i++) {
        pNODE temp = graph->adjList[i];
        fprintf(stdout, "ADJ[%d]:", (i+1));
        if (flag == 2){ //if flag is 2, reverse the adjacency list
        printFlag2(graph->adjList[i]);
        }else{
        while (temp != nullptr) {
            printf("-->[%d %d: %.2f]", (temp->u) + 1, (temp->v)+1, temp->w);
            temp = temp->next;}}
        fprintf(stdout,"\n");}}
//////////////////////////////////////////////////////////// 
void SinglePair(pGRAPH graph, pVERTEX* vertex, int source, int final) {
    for (int i = 0; i < graph->numVertex; i++) {
        vertex[i]->key = DBL_MAX; // Set to a large value, simulating infinity
        vertex[i]->predecessor = -1;}
    vertex[source - 1]->key = 0; //for 0 based indexing
    std::vector<bool> unvisited(graph->numVertex, true);//vector of booleans to check for unvisited
    //dijkstra
    while (true) {
        int u = -1;
        double key = DBL_MAX;
        for (int i = 0; i < graph->numVertex; i++) {
            if (unvisited[i] && vertex[i]->key < key) {
                key = vertex[i]->key;
                u = i;}}
        if (u == -1 || key == DBL_MAX) {
            break;} // break
        //visited
        unvisited[u] = false;
        //relax
        pNODE adj = graph->adjList[u];
        while (adj != nullptr) {
            if (vertex[adj->v]->key > vertex[u]->key + adj->w) {
                vertex[adj->v]->key = vertex[u]->key + adj->w;
                vertex[adj->v]->predecessor = u;}
            adj = adj->next;}}}
//////////////////////////////////////////////////////////// 
void SingleSource(pGRAPH graph, pVERTEX* vertex, int source) {
    for (int i = 0; i < graph->numVertex; i++) {
        vertex[i]->key = DBL_MAX; // Set each vertex key to infinity
        vertex[i]->predecessor = -1; // Set each vertex predecessor to -1
    }
    // Initialize the source vertex
    vertex[source - 1]->key = 0; // Distance from source to source is 0
    std::vector<bool> unvisited(graph->numVertex, true); // Vector to track unvisited vertices
    //dijkstra
    while (true) {
        int u = -1;
        double key = DBL_MAX;
        // Find the vertex with the smallest key value that hasn't been visited yet
        for (int i = 0; i < graph->numVertex; i++) {
            if (unvisited[i] && vertex[i]->key < key) {
                key = vertex[i]->key;
                u = i;}}
        //breaking
        if (u == -1){
            break;}
        unvisited[u] = false;
        //relax
        pNODE adj = graph->adjList[u];
        while (adj != nullptr) {
            if (vertex[adj->v]->key > vertex[u]->key + adj->w) {
                vertex[adj->v]->key = vertex[u]->key + adj->w;
                vertex[adj->v]->predecessor = u;}
            adj = adj->next;}}}
//////////////////////////////////////////////////////////// 
void goAway(pGRAPH graph) {
    if (graph != nullptr) {
        for (int i = 0; i < graph->numVertex; i++) {
            pNODE curr = graph->adjList[i];
            while (curr != nullptr) {
                pNODE temp = curr;
                curr = curr->next;
                free(temp);
            }}
        free(graph->adjList);
        free(graph);
        return; //delete graph and its adjacency list and its contents
    }else{
        fprintf(stderr, "Graph is NULL"); //if graph is null just output to stderr
        return;
    }}
//////////////////////////////////////////////////////////// 
void PrintPath(pGRAPH graph, pVERTEX* vertex, int sourceV, int final) {
    if (vertex[final - 1]->predecessor == -1 || vertex[final - 1]->key == DBL_MAX) {
        fprintf(stdout, "There is no path from %d to %d.\n", sourceV, final);
        return;}
    STACK* stack = init(graph->numVertex);
    for (int i = final-1; i != sourceV - 1; i = vertex[i]->predecessor) {
        if (i == -1) {
            fprintf(stderr, "fail\n");
            stackDelete(stack);
            return;}
    push(stack, vertex[i]);} //create the path 
    push(stack, vertex[sourceV - 1]);
    //printing the path
    fprintf(stdout, "The shortest path from %d to %d is:\n", sourceV, final);
    while (stack->first > 0) {
        pVERTEX vertex = pop(stack); //print the path
        fprintf(stdout, "[%d:%8.2f]", vertex->index + 1, vertex->key); // Adjusting index for 1-based output
        if (stack->first > 0) {
            fprintf(stdout, "-->");}}
    fprintf(stdout, ".\n");
    stackDelete(stack);}
//////////////////////////////////////////////////////////////////////////
void printFlag2(pNODE node) {
    if (node == NULL)return;
    printFlag2(node->next);
    printf("-->[%d %d: %.2f]", (node->u) + 1, (node->v) + 1, node->w);
    return;} //helper method to reverse adjacency list when flag is 2