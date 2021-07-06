#ifndef _CORE_H_
#define _CORE_H_

#include <iostream>
#include <fstream>
#include <string>

namespace Core {
    class Runner {
    private:
        std::ifstream ifs;
        unsigned node;
        unsigned edge;
        unsigned graph;
        unsigned query;
    public:
        enum Err {
            FILE_OPEN
        };
        Runner(std::string fn);
        ~Runner();
        void run(bool verbose, bool graph, bool path);
    };
}

#endif
