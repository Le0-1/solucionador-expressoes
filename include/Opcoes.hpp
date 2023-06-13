#ifndef OPCOES_H
#define OPCOES_H

#include "Resolvedor.hpp"
#include "Pilha.hpp"
#include "ParserExcp.hpp"
#include "ResolvedorExcp.hpp"
#include "TipoNo.hpp"
#include "PilhaExcp.hpp"
#include "Parser.hpp"
#include "ParserExcp.hpp"

/*Essa classe é responsável por fazer as manipulaçãoes no main*/
class Opcoes {
    public:
        Opcoes() = delete;
        static void LerInfixa(Resolvedor &res, std::string &exp);
        static void LerPosfixa(Resolvedor &res, std::string &exp);
        static void ConverteParaPosfixa(Resolvedor &res);
        static void ConverteParaInfixa(Resolvedor &res);
        static void ResolverExpressao(Resolvedor &res);
        static void ImprimirArvore(Resolvedor &res);
};

#endif