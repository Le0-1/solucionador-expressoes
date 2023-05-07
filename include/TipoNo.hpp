#ifndef TIPONO_H
#define TIPONO_H

#include <string>

class TipoNo {
    private:
        std::string _chave;
        TipoNo* _esquerda;
        TipoNo* _direita;

    public:
        TipoNo();
        std::string GetChave();
        void SetChave(std::string chave);
        friend class ArvoreBinaria;
        friend class Resolvedor;
};

#endif