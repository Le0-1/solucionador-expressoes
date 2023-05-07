#include "ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria() {
    this->_raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    
}

void ArvoreBinaria::InsereNo(TipoNo* operador, TipoNo* primeirooperando, TipoNo* segundooperando) {
    operador->_esquerda = primeirooperando;
    operador->_direita = segundooperando;
    this->_raiz = operador;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo* no) {
    if (no != nullptr) {
        ApagaRecursivo(no->_esquerda);
        ApagaRecursivo(no->_direita);
        delete no;
    }
}

void ArvoreBinaria::Limpa() {
    ApagaRecursivo(this->_raiz);
    this->_raiz = nullptr;
}

void ArvoreBinaria::PosOrdem(TipoNo* no) {
    if (no != nullptr) {
        PosOrdem(no->_esquerda);
        PosOrdem(no->_direita);
        std::cout << no->GetChave() << " ";
    }
}

void ArvoreBinaria::ImprimeNo(TipoNo* no, const std::string& prefix, bool ehEsquerda) {
    if (no == nullptr) {
        return;
    }
    std::cout << prefix;
    std::cout << (ehEsquerda? "├──" : "└──");
    std::cout << no->_chave << std::endl;
    ImprimeNo(no->_esquerda, prefix + (ehEsquerda ? "│   " : "    "), true);
    ImprimeNo(no->_direita, prefix + (ehEsquerda ? "│   " : "    "), false);

}

void ArvoreBinaria::ImprimeArvore() {
    if (this->_raiz == nullptr) {
        std::cout << "ERRO: NENHUM NÓ NA ÁRVORE\n";
        return;
    }
    ImprimeNo(this->_raiz, "", false);
}


