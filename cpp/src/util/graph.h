#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

namespace Util {
    class Graph {
    protected:
        struct Node {
        public:
            bool visited;
            size_t prec;
            std::list<size_t> idx;
        };
    private:
        std::vector<Node> al;
    public:
        Graph(std::ifstream &ifs, unsigned node, unsigned edge);
        void log(std::ostream &os);
        bool bfs(size_t src, size_t dest, bool verbose);
    };
}

#endif
