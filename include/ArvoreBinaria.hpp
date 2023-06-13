#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "TipoNo.hpp"

#include <iostream>

/*Classe responsável apenas por fazer as operações necessárias na árvore, algumas funções
não foram utilizadas, como por exemplo: ImprimeArvore(), que imprime uma árvore no terminal
para melhor visualização*/
class ArvoreBinaria {
    private:
        TipoNo* _raiz;
        void InsereNo(TipoNo* operador, TipoNo* primeirooperando, TipoNo* segundooperando);
        void ApagaRecursivo(TipoNo* no);
        void ImprimeNo(TipoNo* no, const std::string& prefix, bool ehEsquerda);
        void PosOrdem(TipoNo* no);

    public:
        void ImprimeArvore();
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Limpa();
        friend class Resolvedor;
};  

#endif