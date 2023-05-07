#include "Resolvedor.hpp"
#include "Pilha.hpp"
#include "TipoNo.hpp"
#include "ResolvedorExcp.hpp"
#include "PilhaExcp.hpp"

#include <sstream>
#include <cstdlib>

Resolvedor::Resolvedor() {
    this->_expressao == "";
}

Resolvedor::Resolvedor(const std::string &exp) {
    this->_expressao = exp;
    this->ConverterParaArvore();
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

char Resolvedor::RetornaUltimoCaractere(const std::string &exp) {
    char Auxiliar = ' ';
    int i = exp.length() - 1;
    while (Auxiliar == ' ') {
        Auxiliar = exp[i];
        i--;
    }
    return Auxiliar;
}

void Resolvedor::SetarExpressao(const std::string &exp) {
    this->_expressao = exp;
    this->ConverterParaArvore();
}

std::string Resolvedor::GetExpressao() {
    if (this->_expressao == "") {
        return "Expressão não foi armazenada\n";
    }
    return this->_expressao;
}

std::string Resolvedor::ParaPOSFIXA() {

    if (this->_expressao == "") {
        std::cout << "ERRO: NENHUMA EXPRESSAO ARMAZENADA\n";
        return "-1";
    }
    char UltimoCaractere = RetornaUltimoCaractere(this->_expressao);

    if (UltimoCaractere == '+' || UltimoCaractere == '-' || UltimoCaractere == '*' || UltimoCaractere == '/') {
        std::cout << "ERRO: EXPRESSAO JÁ É POSFIXA\n";
        return "-1";
    }

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
        
        else if (Token == "+" || Token == "-" || Token == "*" || Token == "/") {

            try {
                while (RetornaPrioridade(Token) <= RetornaPrioridade(PilhaAuxiliar.VerTopo())) {
                    std::string Aux = PilhaAuxiliar.Desempilha();
                    ExpressaoPosfixa+= Aux + " ";
                }
                PilhaAuxiliar.Empilha(Token);
            }
            catch(PilhaExcp::PilhaVazia) {
                PilhaAuxiliar.Empilha(Token);
            }
        }
    }
    while (!PilhaAuxiliar.EstaVazia()) {
        std::string Aux = PilhaAuxiliar.Desempilha();
        ExpressaoPosfixa+= Aux + " ";
    }
    return ExpressaoPosfixa;
}

std::string Resolvedor::ParaINFIXA() {

    if (this->_expressao == "") {
        std::cout << "ERRO: NENHUMA EXPRESSAO ARMAZENADA\n";
        return "-1";
    }
    if (ispunct(RetornaUltimoCaractere(this->_expressao)) || isdigit(RetornaUltimoCaractere(this->_expressao))) {
        std::cout << "ERRO: EXPRESSÃO JÁ É INFIXA\n";
        return "-1";
    }

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
    return ExpressaoInfixa;
}

void Resolvedor::ConverterParaArvore() {
    std::string exp = this->_expressao;

    char UltimoCaractere = RetornaUltimoCaractere(this->_expressao);
    if (!(UltimoCaractere == '+' ||UltimoCaractere == '-' || UltimoCaractere == '*' || UltimoCaractere == '/')) {
        exp = ParaPOSFIXA();
    }

    Pilha<TipoNo*> PilhaDeNos;
    std::string Token;
    std::istringstream Expressao(exp);

    while (Expressao >> Token) {
        if (!ispunct(Token[0])) {
            TipoNo* NovoNo = new TipoNo();
            NovoNo->SetChave(Token);
            PilhaDeNos.Empilha(NovoNo);
        }
        else {
            TipoNo* Operador = new TipoNo();
            TipoNo* SegundoNo = PilhaDeNos.Desempilha();
            TipoNo* PrimeiroNo = PilhaDeNos.Desempilha();
            Operador->SetChave(Token);

            this->_expressao_arvore.InsereNo(Operador, PrimeiroNo, SegundoNo);
            PilhaDeNos.Empilha(Operador); 
        }
    } 
}

double Resolvedor::Resolve(TipoNo* no) {
    if (no == nullptr) {
        return 0.0;
    }

    double ValorEsquerda = Resolve(no->_esquerda);
    double ValorDireita = Resolve(no->_direita);

    if (std::isdigit(no->_chave[0])) {
        return std::stod(no->_chave);
    }
    else if (no->_chave == "+") {
        return ValorEsquerda + ValorDireita;
    }
    else if (no->_chave == "-") {
        return ValorEsquerda - ValorDireita;
    }
    else if (no->_chave == "*") {
        return ValorEsquerda * ValorDireita;
    }
    else if (no->_chave == "/") {
        if (ValorDireita == 0) {
            throw ResolvedorExcp::DivisorZero();
        }
        return ValorEsquerda / ValorDireita;
    }
}

double Resolvedor::Resolve() {
    if (this->_expressao_arvore._raiz == nullptr) {
        std::cout << "ERRO: NÃO HÁ NENHUM NÓ NA ÁRVORE\n";
        return -1;
    }
    Resolve(this->_expressao_arvore._raiz);
}

ArvoreBinaria Resolvedor::GetArvore() {
    return this->_expressao_arvore;
}