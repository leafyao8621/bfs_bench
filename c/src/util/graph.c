#include <stdlib.h>
#include "graph.h"

struct ListNode {
    size_t data;
    struct ListNode *next;
};

struct Node {
    char visited;
    size_t prec;
    struct ListNode *root;
};

static void push(struct ListNode **ln, size_t data) {
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp->next = *ln;
    temp->data = data;
    *ln = temp;
}

void util_graph_initialize(struct Graph *g,
                           FILE *fin,
                           size_t node,
                           size_t edge) {
    g->node = node;
    g->edge = edge;
    g->al = malloc(sizeof(struct Node) * node);
    struct Node *iter_al = g->al;
    for (size_t i = 0; i < node; ++i, ++iter_al) {
        iter_al->visited = 0;
        iter_al->root = 0;
    }
    for (size_t i = 0; i < edge; ++i) {
        size_t src, dest;
        fscanf(fin, "%lu %lu", src, dest);
        push(&g->al[src].root, dest);
        push(&g->al[dest].root, src);
    }
}
