#include "ParserExcp.hpp"

ParserExcp::TokenAnomalo::TokenAnomalo(std::string token) {
    this->_token = token;
}

const char* ParserExcp::TokenAnomalo::what() const throw() {
    return "ERRO 🕵️: Token na expressão foi considerado inválido: ";
}

std::string ParserExcp::TokenAnomalo::GetToken() {
    return this->_token;
}