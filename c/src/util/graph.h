#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>

struct Graph {
    size_t node, edge;
    struct Node *al;
};

void util_graph_initialize(struct Graph *g,
                           FILE *fin,
                           size_t node,
                           size_t edge);
void util_graph_finalize(struct Graph *g);
void util_graph_log(struct Graph *g, FILE *fout);
char util_graph_bfs(struct Graph *g, size_t src, size_t dest, char verbose);

#endif
