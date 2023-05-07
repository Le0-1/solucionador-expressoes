#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "TipoNo.hpp"

#include <iostream>

class ArvoreBinaria {
    private:
        TipoNo* _raiz;
        void InsereNo(TipoNo* operador, TipoNo* primeirooperando, TipoNo* segundooperando);
        void ApagaRecursivo(TipoNo* no);
        void ImprimeNo(TipoNo* no, const std::string& prefix, bool ehEsquerda);
        void PosOrdem(TipoNo* no);

    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Limpa();
        void ImprimeArvore();
        friend class Resolvedor;
};  

#endif