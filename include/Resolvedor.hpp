#ifndef RESOLVEDOR_H
#define RESOLVEDOR_H

#include <string>
#include <iostream>

#define SOMA = "+"
#define SUBTRACAO = "-"
#define MULTIPLICACAO = "*"
#define DIVISAO = "/"

class Resolvedor {  
    private:
        std::string _expressao;
        int RetornaPrioridade(const std::string &token);
    public:
        Resolvedor();
        Resolvedor(const std::string &exp);
        std::string GetExpressao();
        void SetarExpressao(const std::string &exp);
        std::string ParaPOSFIXA();
        std::string ParaINFIXA();
        double Resolve();
};

#endif