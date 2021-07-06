#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "../util/mt19937.h"

void core_generate(unsigned seed,
                   unsigned node,
                   unsigned edge,
                   unsigned graph,
                   unsigned query,
                   FILE *fout) {
    struct MT19937 gen;
    mt19937_initialize(&gen, seed);
    fprintf(fout, "%d %d %d %d\n", node, edge, graph, query);
    size_t len = node * (node - 1) / 2;
    char *am = malloc(len);
    for (unsigned i = 0; i < graph; ++i) {
        memset(am, 0, len);
        for (unsigned j = 0; j < edge; ++j) {
            unsigned int a, b;
            do {
                a = mt19937_gen(&gen) % node;
                b = mt19937_gen(&gen) % node;
                if (a == b) {
                    continue;
                }
                if (a < b) {
                    int c = a;
                    a = b;
                    b = c;
                }
            } while (am[a * (a - 1) / 2 + b]);
            am[a * (a - 1) / 2 + b] = 1;
            fprintf(fout, "%u %u\n", a, b);
        }
        for (int j = 0; j < query; ++j) {
            unsigned int a, b;
            do {
                a = mt19937_gen(&gen) % node;
                b = mt19937_gen(&gen) % node;
            } while (a == b);
            fprintf(fout, "%u %u\n", a, b);
        }
    }
}
