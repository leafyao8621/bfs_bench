#ifndef _CORE_H_
#define _CORE_H_

#include <stdio.h>

struct Runner {
    FILE *fin;
    size_t node, edge, graph, query;
};

char core_runner_initialize(struct Runner *r, const char *fn);
void core_runner_finalize(struct Runner *r);
void core_runner_run(struct Runner *r, char verbose, char graph, char path);

#endif
