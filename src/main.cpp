#include "Pilha.hpp"
#include "Parser.hpp"
#include "Resolvedor.hpp"
#include "ParserExcp.hpp"
#include "ResolvedorExcp.hpp"
#include "ArvoreBinaria.hpp"
#include "TipoNo.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

enum Escolha {
    LER_INFIXA,
    LER_POSFIXA,
    CONVERTE_PARA_INFIXA,
    CONVERTE_PARA_POSFIXA,
    RESOLVE_EXPRESSAO,
    MOSTRAR_ARVORE,
    EXIBIR_MENU,
    SAIR
};

void ExibirMenu() {
    std::cout
        << "---------------------------------\n"
        << "0 - LER_INFIXA\n"
        << "1 - LER_POSFIXA\n"
        << "2 - CONVERTE_PARA_INFIXA\n"
        << "3 - CONVERTE_PARA_POSFIXA\n"
        << "4 - RESOLVE_EXPRESSAO\n"
        << "5 - MOSTRAR_ARVORE\n"
        << "6 - EXIBIR_MENU\n"
        << "7 - SAIR\n";
        return;    
}
int main() {
    ExibirMenu();

    unsigned Escolha;
    std::string Expressao;
    Resolvedor Solucionador;
    bool KeepGoing = 1;

    while (KeepGoing) {
        std::cin >> Escolha;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (Escolha) {

            case LER_INFIXA: {
                std::system("clear");

                std::cout << "DIGITE A EXPRESSAO: \n";
                std::getline(std::cin, Expressao);

                try {
                    if (Parser::ValidarInfixa(Expressao)) {
                        Solucionador.SetarExpressao(Expressao);
                        std::cout << "EXPRESSAO ARMAZENADA COM SUCESSO\n";
                    }
                    else {
                        std::cout << "EXPRESSAO NÃO FOI ARMAZENADA\n";
                    }
                }   
                catch (ParserExcp::TokenAnomalo& e) {
                    std::cout << e.what() << e.GetToken() << "\n";
                }
                ExibirMenu();
                break;
            }

            case LER_POSFIXA: {
                std::system("clear");

                std::cout << "DIGITE A EXPRESSAO: \n";
                std::getline(std::cin, Expressao);

                try {
                    if (Parser::ValidarPosfixa(Expressao)) {
                        Solucionador.SetarExpressao(Expressao);
                        std::cout << "EXPRESSAO ARMAZENADA COM SUCESSO\n";
                    }
                    else {
                        std::cout << "EXPRESSAO NÃO FOI ARMAZENADA\n";
                    }
                }
                catch (ParserExcp::TokenAnomalo& e) {
                    std::cout << e.what() << e.GetToken() << "\n";
                }
                ExibirMenu();
                break;
            }

            case CONVERTE_PARA_INFIXA: {
                std::system("clear");
                std::string ExpressaoInfixa;
                ExpressaoInfixa = Solucionador.ParaINFIXA();
                if (ExpressaoInfixa == "-1") {
                    std::cout << "CONVERSÃO FALHOU\n";
                }
                else {
                    std::cout << "CONVERSÃO CONCLUÍDA\n";
                    std::cout << ExpressaoInfixa << "\n";
                }
                ExibirMenu();
                break;
            }

            case CONVERTE_PARA_POSFIXA: {
                std::system("clear");
                std::string ExpressaoPosfixa;
                ExpressaoPosfixa = Solucionador.ParaPOSFIXA();
                if (ExpressaoPosfixa == "-1") {
                    std::cout << "CONVERSÃO FALHOU\n";
                }
                else {
                    std::cout << "CONVERSÃO CONCLUÍDA\n";
                    std::cout << ExpressaoPosfixa << "\n";
                }
                ExibirMenu();
                break;  
            }

            case RESOLVE_EXPRESSAO: {
                std::system("clear");
                double Resultado = -1;
                try {
                    Resultado = Solucionador.Resolve();
                }
                catch (ResolvedorExcp::DivisorZero& e) {
                    e.what();
                }
                if (Resultado == -1) {
                    std::cout << "NÃO FOI POSSÍVEL RESOLVER A EXPRESSÃO\n";
                }
                else {
                    std::cout
                    << "RESULTADO DA EXPRESSÃO: "
                    << std::fixed 
                    << std::setprecision(6)
                    << Resultado << "\n";
                }
                ExibirMenu();
                break;
            }

            case MOSTRAR_ARVORE: {
                
                std::system("clear");
                Solucionador.GetArvore().ImprimeArvore();
                ExibirMenu();
                break;
            }

            case EXIBIR_MENU: {
                std::system("clear");
                ExibirMenu();
                break;
            }

            case SAIR: {
                std::system("clear");
                KeepGoing = 0;
                ExibirMenu();
                break;
            }
        }

    }
    
    Solucionador.GetArvore().Limpa();
    return 0;
}