#include "Pilha.hpp"
#include "Parser.hpp"
#include "Resolvedor.hpp"

#include <iostream>
#include <string>

int main() {
    std::string exp = "( ( ( ( ( ( ( 1.430560 ) / ( 6.889632 ) ) / ( ( ( ( 2.255391 ) + ( 9.655282 ) ) - ( 2.075334 ) ) + ( ( 0.822038 ) * ( 7.007894 ) ) ) ) - ( ( ( ( 9.827914 ) - ( ( 3.516262 ) / ( 6.577532 ) ) ) * ( 2.560684 ) ) / ( 9.362095 ) ) ) - ( ( ( 5.562911 ) + ( 7.878364 ) ) + ( 9.584948 ) ) ) * ( 4.856426 ) ) * ( ( ( ( ( 0.766523 ) / ( 6.980499 ) ) + ( ( 8.642408 ) - ( 3.041649 ) ) ) * ( ( 0.327483 ) - ( 7.814537 ) ) ) / ( ( 9.022130 ) - ( ( ( 0.797961 ) * ( 6.797215 ) ) + ( 0.093923 ) ) ) ) )";

    if(Parser::ValidarInfixa(exp)) {
        Resolvedor sistema(exp);
        std::cout << "Certo 1\n";
        std::cout << sistema.GetExpressao() << "\n";
        std::cout << "---------------------------------------------------------------------------\n";
        if(Parser::ValidarPosfixa(sistema.ParaPOSFIXA())) {
            std::cout << "Certo 2\n";
            std::cout << sistema.GetExpressao() << "\n";
            std::cout << "---------------------------------------------------------------------------\n";
            if(Parser::ValidarInfixa(sistema.ParaINFIXA())) {
                std::cout << "Certo 3\n";
                std::cout << sistema.GetExpressao() << "\n";
                std::cout << "---------------------------------------------------------------------------\n";
                if(Parser::ValidarPosfixa(sistema.ParaPOSFIXA())) {
                    std::cout << "Certo 4\n";
                    std::cout << sistema.GetExpressao() << "\n";
                    std::cout << "---------------------------------------------------------------------------\n";
                }
            }
        }
    }
}