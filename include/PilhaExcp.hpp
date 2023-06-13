#ifndef PILHAEXCP_H
#define PILHAEXCP_H

#include <exception>

/*Implementa apenas a exceção de pilha vazia*/
namespace PilhaExcp {

    class PilhaVazia : public std::exception {
        public:
            const char* what() throw();
    };
}

#endif