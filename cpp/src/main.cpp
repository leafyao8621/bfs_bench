#include "core/core.h"

int main(int argc, char **argv) {
    Core::Runner r("../in/bench.in");
    r.run(false, false, false);
    return 0;
}
