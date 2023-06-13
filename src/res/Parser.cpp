#include "Parser.hpp"
#include "ParserExcp.hpp"

#include <sstream>
#include <cctype>

/* Cada expressão tem que ter pelo menos N operandos e N-1 operadores, 
é uma verificação genérica */
bool Parser::ValidacaoGenerica(const std::string& exp) {
    std::istringstream Expressao(exp);
    std::string Token;

    int NumeroDeOperadores = 0, NumeroDeOperandos = 0;

    while (Expressao >> Token) {
        if (EhOperadorValido(Token)) {
            NumeroDeOperadores++;
        }
        else if (EhNumeroValido(Token)) {
            NumeroDeOperandos++;
        }
        else if (Token != "(" && Token != ")") {
            throw ParserExcp::TokenAnomalo(Token);
        }
    }

    if (NumeroDeOperadores == (NumeroDeOperandos - 1)) {
        return true;
    }
    else {
        return false;
    }
}

bool Parser::EhOperadorValido(const std::string& exp) {
    if (exp == "+" || exp == "-" || exp == "*" || exp == "/") {
        return true;
    }
    else return false;
}

/*Verifica dentro do número se há algum caractere estranho nele, se há mais de um ponto ou se não contem dígitos*/
bool Parser::EhNumeroValido(const std::string& token) {
    int NumeroDePontos = 0, NumeroDeDigitos = 0;

    for (unsigned i = 0; i < token.length(); i++) {
        if (token[i] == '.') {
            NumeroDePontos++;
        }
        else if (isdigit(token[i])) {
            NumeroDeDigitos++;
        }
        else {
            return false;
        }
    }
    if (NumeroDePontos > 1 || NumeroDeDigitos == 0) {
        return false;
    }
    else return true;
}

bool Parser::ValidarInfixa(const std::string &exp) {
    if (ValidacaoGenerica(exp) == false) {
        return false;
    }
    if (VerificarParenteses(exp) == false) {
        return false;
    }
    return true;

}

bool Parser::ValidarPosfixa(const std::string &exp) {
    if (exp.find(")") != std::string::npos || exp.find("(") != std::string::npos) {
        return false;
    }

    /*Tem que existir N operandos e N-1 operadores*/
    if (ValidacaoGenerica(exp) == false) {
        return false;
    }

    /*O último Token tem que ser um operador*/
    std::string UltimoToken;
    for (int i = exp.length(); i >= 0; i--) {
        if (ispunct(exp[i])) {
            std::string UltimoCaractere(1, exp[i]);
            UltimoToken = UltimoCaractere;
            break;
        }
    }
    if (!EhOperadorValido(UltimoToken)) {
        return false;
    }

    /*Os 2 primeiros tokens tem que ser operandos*/
    std::istringstream Expressao(exp);
    std::string PrimeiroToken, SegundoToken;

    Expressao >> PrimeiroToken >> SegundoToken;

    if (EhNumeroValido(PrimeiroToken) && EhNumeroValido(SegundoToken)) {
        return true;
    }
    else {
        return false;
    }
}

/*Verifica a disposição dos parentêses, além de contar quantos foram abertos e fechados,
realizando uma verificação mais ampla*/
bool Parser::VerificarParenteses(const std::string &exp) {
    int Contador = 0, ParentesesAbertos = 0, ParentesesFechados = 0;

    for (int i = exp.length(); i >= 0; i--) {
        if (exp[i] == '(') {
            Contador--;
            ParentesesAbertos++;
        }
        
        else if (exp[i] == ')') {
            Contador++;
            ParentesesFechados++;
        }

        else if (Contador < 0) {
            return false;
        }
    }
    if ((Contador != 0) || (ParentesesAbertos != ParentesesFechados)){ 
        return false;
    }
    else return true;
}