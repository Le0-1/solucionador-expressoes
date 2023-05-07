#include "TipoNo.hpp"

TipoNo::TipoNo() {
    this->_chave = "";
    this->_direita = nullptr;
    this->_esquerda = nullptr;
}

std::string TipoNo::GetChave() {
    return this->_chave;
}

void TipoNo::SetChave(std::string chave) {
    this->_chave = chave;
}