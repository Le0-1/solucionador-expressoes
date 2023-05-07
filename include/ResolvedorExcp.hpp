#ifndef RESOLVEDOREXCP_H
#define RESOLVEDOREXCP_H

#include <exception>

namespace ResolvedorExcp {

    class DivisorZero : public std::exception {
        public:
            DivisorZero();
            const char* what() const throw();
    };
}
#endif
