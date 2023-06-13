#ifndef PARSEREXCP_H
#define PARSEREXCP_H

#include <exception>
#include <string>

/*Exceção a ser lançada quando encontrar algum caractere estranho na expressão*/
namespace ParserExcp {

    class TokenAnomalo : public std::exception {
        private:
            std::string _expressao;

        public:
            TokenAnomalo(std::string expressao);
            const char* what() const throw();
            std::string GetExpressao();
    };
}

#endif