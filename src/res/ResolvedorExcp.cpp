#include "ResolvedorExcp.hpp"

ResolvedorExcp::DivisorZero::DivisorZero() {
    
}

const char* ResolvedorExcp::DivisorZero::what() const throw() {
    return "ERRO 🕵️: Divisor é ZERO\n";
}