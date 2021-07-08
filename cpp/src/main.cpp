#include "core/core.h"

int main(int argc, char **argv) {
    if (argc != 5) {
        std::cout << "infile verbose graph path\n";
        return 1;
    }
    std::ios::sync_with_stdio(false);
    try {
        Core::Runner r(argv[1]);
        r.run(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    } catch (Core::Runner::Err e) {
        std::cout << "infile verbose graph path\n";
        return 1;
    }
    return 0;
}
