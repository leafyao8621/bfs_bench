#include <algorithm>
#include "graph.h"

Util::Graph::Graph(std::ifstream &ifs, unsigned node, unsigned edge) {
    this->node = node;
    this->al = new Node[node];
    for (int i = 0; i < edge; ++i) {
        size_t src, dest;
        ifs >> src >> dest;
        this->al[src].idx.push_back(dest);
        this->al[dest].idx.push_back(src);
    }
}

Util::Graph::~Graph() {
    delete[] this->al;
}

void Util::Graph::log(std::ostream &os) {
    size_t ci = 0;
    Node *iter = this->al;
    for (size_t i = 0; i < this->node; ++i, ++iter) {
        os << ci << ":";
        for (auto &j : iter->idx) {
            os << ' ' << j;
        }
        os << '\n';
        ++ci;
    }
}

bool Util::Graph::bfs(size_t src, size_t dest, bool verbose) {
    std::list<size_t> queue;
    queue.push_back(src);
    Node *iter = this->al;
    for (size_t i = 0; i < this->node; ++i, ++iter) {
        iter->visited = false;
    }
    for (; !queue.empty(); ) {
        size_t cur = queue.front();
        queue.pop_front();
        if (cur == dest) {
            if (verbose) {
                size_t i = dest;
                std::cout << dest;
                for (i = this->al[i].prec; i != src; i = this->al[i].prec) {
                    std::cout << "<-\n" << i;
                }
                std::cout << "<-\n" << src << '\n';
            }
            return true;
        }
        this->al[cur].visited = true;
        for (auto &i : this->al[cur].idx) {
            if (!this->al[i].visited) {
                this->al[i].prec = cur;
                queue.push_back(i);
            }
        }
    }
    return false;
}
