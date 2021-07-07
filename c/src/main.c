#include <stdlib.h>
#include "core/core.h"

int main(int argc, const char **argv) {
    if (argc != 5) {
        puts("infile verbose graph path");
        return 1;
    }
    struct Runner r;
    char ret = core_runner_initialize(&r, argv[1]);
    if (ret) {
        puts("infile verbose graph path");
        return 1;
    }
    core_runner_run(&r, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    core_runner_finalize(&r);
    return 0;
}
