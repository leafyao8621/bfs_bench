#include "core.h"
#include "../util/graph.h"

char core_runner_initialize(struct Runner *r, const char *fn) {
    r->fin = fopen(fn, "r");
    if (!r->fin) {
        return 1;
    }
    fscanf(r->fin, "%lu %lu %lu %lu",
           &r->node,
           &r->edge,
           &r->graph,
           &r->query);
    return 0;
}

void core_runner_finalize(struct Runner *r) {
    fclose(r->fin);
}

void core_runner_run(struct Runner *r, char verbose, char graph, char path) {
    for (size_t i = 0; i < r->graph; ++i) {
        if (verbose) {
            printf("graph %lu\n", i);
        }
        struct Graph g;
        util_graph_initialize(&g, r->fin, r->node, r->edge);
        if (graph) {
            util_graph_log(&g, stdout);
        }
        for (size_t j = 0; j < r->query; ++j) {
            size_t src, dest;
            fscanf(r->fin, "%lu %lu", &src, &dest);
            char ret = util_graph_bfs(&g, src, dest, path);
            if (verbose) {
                printf("%lu %s %u\n", src, ret ? "->" : "X", dest);
            }
        }
        util_graph_finalize(&g);
    }
}
