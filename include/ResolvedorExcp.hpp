#ifndef RESOLVEDOREXCP_H
#define RESOLVEDOREXCP_H

#include <exception>

/*Implementa duas exceções: quando o divisor for zero, logo a conta não pode ser
resolvida ou quando a expressão não foi armazenada e nada existe na árvore,
não sendo possível resolver a expressão*/
namespace ResolvedorExcp {

    class DivisorZero : public std::exception {
        public:
            DivisorZero();
            const char* what() const throw();
    };
    class ArvoreVazia : public std::exception {
        public:
            ArvoreVazia();
            const char* what() const throw();
    };
}
#endif
