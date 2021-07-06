#ifndef _CORE_H_
#define _CORE_H_

#include <stdio.h>

void core_generate(unsigned seed,
                   unsigned node,
                   unsigned edge,
                   unsigned graph,
                   unsigned query,
                   FILE *fout);

#endif
