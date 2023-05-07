#ifndef RESOLVEDOR_H
#define RESOLVEDOR_H

#include "ArvoreBinaria.hpp"

#include <string>
#include <iostream>

class Resolvedor {  
    private:
        ArvoreBinaria _expressao_arvore;
        std::string _expressao;
        int RetornaPrioridade(const std::string &token);
        void ConverterParaArvore();
        double Resolve(TipoNo* no);
        char RetornaUltimoCaractere(const std::string &exp);

    public:
        Resolvedor();
        Resolvedor(const std::string &exp);
        std::string GetExpressao();
        ArvoreBinaria GetArvore();
        void SetarExpressao(const std::string &exp);
        std::string ParaPOSFIXA();
        std::string ParaINFIXA();
        double Resolve();
};

#endif