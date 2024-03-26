
#ifndef _graph_h
#define _graph_h_ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"
pGRAPH makeGraph(int numVertex, int numEdge);
void goAway(pGRAPH graph);
void SinglePair(pGRAPH graph, pVERTEX* vertex, int source, int final);
void add(pGRAPH graph, int u, int v, double w, int direction);
void printADJ(pGRAPH graph, int flag);
void SingleSource(pGRAPH graph, pVERTEX* vertex, int source);
void PrintLength(pVERTEX* vertex, int sourceV, int final);
void PrintPath(pGRAPH graph, pVERTEX* vertex, int sourceV, int final);
void printFlag2(pNODE node);
#endif