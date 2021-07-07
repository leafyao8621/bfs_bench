#include <stdlib.h>
#include <string.h>
#include "core/core.h"

int main(int argc, char **argv) {
    if (argc != 7) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    unsigned seed = atoi(argv[1]);
    if (seed == -1) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    unsigned node = atoi(argv[2]);
    if (node == -1) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    unsigned edge = atoi(argv[3]);
    if (edge == -1) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    unsigned graph = atoi(argv[4]);
    if (graph == -1) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    unsigned query = atoi(argv[5]);
    if (query == -1) {
        puts("please pass in seed, node, edge, graph, query, fout");
        return 1;
    }
    FILE *fout = strcmp("-", argv[6]) ?
                 fopen(argv[6], "w") :
                 stdout;
    if (!fout) {
        printf("please pass in node, edge, graph, query, fout");
        return 1;
    }
    core_generate(seed,
                  node,
                  edge,
                  graph,
                  query,
                  fout);
    fclose(fout);
    return 0;
}
