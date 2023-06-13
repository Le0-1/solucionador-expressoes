#include "ParserExcp.hpp"

ParserExcp::TokenAnomalo::TokenAnomalo(std::string expressao) {
    this->_expressao = expressao;
}

const char* ParserExcp::TokenAnomalo::what() const throw() {
    return "ERRO: ENCONTRADO TOKEN ANÔMALO: ";
}

std::string ParserExcp::TokenAnomalo::GetExpressao() {
    return this->_expressao;
}