#include "Opcoes.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>

void Opcoes::LerInfixa(Resolvedor &res, std::string &exp) {
    std::getline(std::cin, exp);
    try {
        if (Parser::ValidarInfixa(exp)) {
            res.SetarExpressao(exp);
            std::cout << "EXPRESSÃO OK:" << exp << '\n';
            Opcoes::ImprimirArvore(res);
        }
        else {
            std::cout << "ERRO: " << exp << " NAO VÁLIDA\n";
        }
    }   
    catch (ParserExcp::TokenAnomalo& e) {
        std::cout << e.what() << e.GetExpressao() << '\n';
    }
}

void Opcoes::LerPosfixa(Resolvedor &res, std::string &exp) {

    std::getline(std::cin, exp);

    try {
        if (Parser::ValidarPosfixa(exp)) {
            res.SetarExpressao(exp);
            std::cout << "EXPRESSÃO OK:" << exp << "\n";
            Opcoes::ImprimirArvore(res);
        }
        else {
            std::cout << "ERRO: " << exp << " NAO VÁLIDA\n";
        }
    }
    catch (ParserExcp::TokenAnomalo& e) {
        std::cout << e.what() << e.GetExpressao() << '\n';
    }
}

void Opcoes::ConverteParaInfixa(Resolvedor &res) {
    std::string ExpressaoInfixa;
    ExpressaoInfixa = res.ParaINFIXA();
    if (ExpressaoInfixa == "-1") {
        std::cout << "ERRO: EXP NÃO EXISTE\n";
    }
    else {
        std::cout << "INFIXA: ";
        std::cout << ExpressaoInfixa << "\n";
    }
}

void Opcoes::ConverteParaPosfixa(Resolvedor &res) {
    std::string ExpressaoPosfixa;
    ExpressaoPosfixa = res.ParaPOSFIXA();
    if (ExpressaoPosfixa == "-1") {
        std::cout << "ERRO: EXP NÃO EXISTE\n";
    }
    else {
        std::cout << "POSFIXA: ";
        std::cout << ExpressaoPosfixa << "\n";
    }
}

void Opcoes::ResolverExpressao(Resolvedor &res) {
    double Resultado;
    try {
        Resultado = res.Resolve();
        std::cout
        << "VAL : "
        << std::fixed 
        << std::setprecision(6)
        << Resultado << "\n";
        std::cout << "----------------------------------------------\n";
        return;
    }
    catch (ResolvedorExcp::DivisorZero& e) {
        std::cout << e.what();
    }
    catch (ResolvedorExcp::ArvoreVazia& e) {
        std::cout << e.what();
    }
}

void Opcoes::ImprimirArvore(Resolvedor &res) {
    res.GetArvore().ImprimeArvore();
    return;
}