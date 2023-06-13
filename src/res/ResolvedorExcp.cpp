#include "ResolvedorExcp.hpp"

ResolvedorExcp::DivisorZero::DivisorZero() {
    
}

const char* ResolvedorExcp::DivisorZero::what() const throw() {
    return "ERRO 🕵️: Não foi possível calcular o valor pois o Divisor é ZERO\n";
}

ResolvedorExcp::ArvoreVazia::ArvoreVazia() {
    
}

const char* ResolvedorExcp::ArvoreVazia::what() const throw() {
    return "ERRO: EXP NÃO EXISTE\n";
}