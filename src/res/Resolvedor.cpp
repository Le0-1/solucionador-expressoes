#include "Resolvedor.hpp"
#include "Pilha.hpp"

#include <sstream>

Resolvedor::Resolvedor() {

}

Resolvedor::Resolvedor(const std::string &exp) {
    this->_expressao = exp;
}

int Resolvedor::RetornaPrioridade(const std::string &token) {
    if (token == "+" || token == "-") {
        return 1;
    }
    else if (token == "*" || token == "/") {
        return 2;
    }
    else return 0;
}

void Resolvedor::SetarExpressao(const std::string &exp) {
    this->_expressao = exp;
}

std::string Resolvedor::GetExpressao() {
    return this->_expressao;
}

std::string Resolvedor::ParaPOSFIXA() {
    Pilha<std::string> PilhaAuxiliar;

    std::string ExpressaoPosfixa = "", Token;
    std::istringstream Escaner(this->_expressao);

    while(Escaner >> Token) {
        if (!ispunct(Token[0])) {
            ExpressaoPosfixa+= Token + " ";
        }

        else if (Token == "(") {
            PilhaAuxiliar.Empilha(Token);
        }

        else if (Token == ")") {

            while (PilhaAuxiliar.VerTopo() != "(") {
                std::string Aux = PilhaAuxiliar.Desempilha();
                ExpressaoPosfixa+= Aux + " ";
            }
            PilhaAuxiliar.Desempilha();
        }
        
        else if (RetornaPrioridade(Token) <= RetornaPrioridade(PilhaAuxiliar.VerTopo())) {
            
            while (RetornaPrioridade(Token) <= RetornaPrioridade(PilhaAuxiliar.VerTopo())) {
                std::string Aux = PilhaAuxiliar.Desempilha();
                ExpressaoPosfixa+= Aux + " ";
            }
            PilhaAuxiliar.Empilha(Token);
        }
        else {
            PilhaAuxiliar.Empilha(Token);
        }
    }
    this->_expressao = ExpressaoPosfixa;
    return ExpressaoPosfixa;
}

std::string Resolvedor::ParaINFIXA() {
    Pilha<std::string> PilhaAuxiliar;
    std::istringstream Escaner(this->_expressao);
    std::string Token, ExpressaoInfixa = "";

    while (Escaner >> Token) {
        if (!ispunct(Token[0])) {
            PilhaAuxiliar.Empilha(Token);
        }
        else {
            std::string SegundoOperando = PilhaAuxiliar.Desempilha();
            std::string PrimeiroOperando = PilhaAuxiliar.Desempilha();
            ExpressaoInfixa = "( " + PrimeiroOperando + " " + Token + " " + SegundoOperando + " )";
            PilhaAuxiliar.Empilha(ExpressaoInfixa);
        }
    }
    this->_expressao = ExpressaoInfixa;
    return ExpressaoInfixa;
}