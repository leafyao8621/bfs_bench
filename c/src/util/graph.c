#include <stdlib.h>
#include "graph.h"

struct ListNode {
    size_t data;
    struct ListNode *next;
};

struct List {
    struct ListNode *front, *back;
};

struct Node {
    char visited;
    size_t prec;
    struct List idx;
};

static inline void push(struct List *l, size_t data) {
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp->next = 0;
    temp->data = data;
    if (!l->front) {
        l->front = temp;
    }
    if (l->back) {
        l->back->next = temp;
    }
    l->back = temp;
}

static inline void pop(struct List *l) {
    if (!l->front) {
        return;
    }
    struct ListNode *temp = l->front;
    l->front = l->front->next;
    if (!l->front) {
        l->back = 0;
    }
    free(temp);
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
        iter_al->idx.front = 0;
        iter_al->idx.back = 0;
    }
    for (size_t i = 0; i < edge; ++i) {
        size_t src, dest;
        fscanf(fin, "%lu %lu", &src, &dest);
        push(&g->al[src].idx, dest);
        push(&g->al[dest].idx, src);
    }
}

void util_graph_finalize(struct Graph *g) {
    struct Node *iter_al = g->al;
    for (size_t i = 0; i < g->node; ++i, ++iter_al) {
        for (; iter_al->idx.front; pop(&iter_al->idx));
    }
    free(g->al);
}

void util_graph_log(struct Graph *g, FILE *fout) {
    struct Node *iter_al = g->al;
    for (size_t i = 0; i < g->node; ++i, ++iter_al) {
        fprintf(fout, "%lu:", i);
        for (struct ListNode *iter_idx = iter_al->idx.front;
             iter_idx;
             iter_idx = iter_idx->next) {
            fprintf(fout, " %lu", iter_idx->data);
        }
        putchar(10);
    }
}

char util_graph_bfs(struct Graph *g, size_t src, size_t dest, char verbose) {
    struct List queue;
    queue.front = 0;
    queue.back = 0;
    struct Node *iter = g->al;
    for (size_t i = 0; i < g->node; ++i, ++iter) {
        iter->visited = 0;
    }
    g->al[src].visited = 1;
    push(&queue, src);
    for (; queue.front;) {
        size_t cur = queue.front->data;
        pop(&queue);
        if (cur == dest) {
            if (verbose) {
                printf("%lu", dest);
                for (size_t i = g->al[dest].prec;
                     i != src;
                     i = g->al[i].prec) {
                    printf("<-\n%lu", i);
                }
                printf("<-\n%lu\n", src);
            }
            for (; queue.front; pop(&queue));
            return 1;
        }
        for (struct ListNode *i = g->al[cur].idx.front;
             i;
             i = i->next) {
            if (!g->al[i->data].visited) {
                g->al[i->data].visited = 1;
                g->al[i->data].prec = cur;
                push(&queue, i->data);
            }
        }
    }
    for (; queue.front; pop(&queue));
    return 0;
}
