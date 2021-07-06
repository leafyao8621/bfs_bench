#include <string>
#include "core.h"
#include "../util/graph.h"

Core::Runner::Runner(std::string fn) {
    this->ifs.open(fn);
    if (this->ifs.fail()) {
        throw Core::Runner::Err::FILE_OPEN;
    }
    ifs >> this->node >> this->edge >> this->graph >> this->query;
}

Core::Runner::~Runner() {
    this->ifs.close();
}

void Core::Runner::run(bool verbose, bool graph, bool path) {
    for (int i = 0; i < this->graph; ++i) {
        if (verbose) {
            std::cout << "graph " << i << '\n';
        }
        Util::Graph g(this->ifs, this->node, this->edge);
        if (graph) {
            g.log(std::cout);
        }
        for (int j = 0; j < query; ++j) {
            size_t src, dest;
            if (verbose) {
                std::cout << "query " << j << '\n';
            }
            this->ifs >> src >> dest;
            bool res = g.bfs(src, dest, path);
            if (verbose) {
                std::cout << src << (res ? " -> " : " X ") << dest << '\n';
            }
        }
    }
}
