#ifndef PILHAEXCP_H
#define PILHAEXCP_H

#include <exception>

namespace PilhaExcp {

    class PilhaVazia : public std::exception {
        public:
            const char* what() throw();
    };
}

#endif