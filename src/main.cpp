#include "Pilha.hpp"
#include "Parser.hpp"
#include "Resolvedor.hpp"
#include "ParserExcp.hpp"
#include "ResolvedorExcp.hpp"
#include "ArvoreBinaria.hpp"
#include "TipoNo.hpp"
#include "Opcoes.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include <chrono>
#include <iomanip>

int main() {
    std::string Escolha, Expressao;
    Resolvedor Solucionador;

    while (std::cin >> Escolha) {

        if (Escolha == "LER") {
            std::cin >> Escolha;
            if (Escolha == "INFIXA") {
                Opcoes::LerInfixa(Solucionador, Expressao);
            }
            else if (Escolha == "POSFIXA") {
                Opcoes::LerPosfixa(Solucionador, Expressao);
            }
        }
        else if (Escolha == "POSFIXA") {
            Opcoes::ConverteParaPosfixa(Solucionador);
        }
        else if (Escolha == "INFIXA")  {
            Opcoes::ConverteParaInfixa(Solucionador);
        }
        else if (Escolha == "RESOLVE")  {
            Opcoes::ResolverExpressao(Solucionador);
        }
    }
    Solucionador.GetArvore().Limpa();
    return 0;
}