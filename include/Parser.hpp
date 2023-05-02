#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>

class Parser {
    private:
        static bool EhOperadorValido(const std::string &token);
        static bool EhNumeroValido(const std::string &token);
        static bool VerificarParenteses(const std::string &exp);
        static bool ValidacaoGenerica(const std::string &exp);
        std::string RetornaUltimoToken(const std::string &exp);
    public:
        Parser() = delete;
        static bool ValidarPosfixa(const std::string &exp);
        static bool ValidarInfixa(const std::string &exp);
};

#endif