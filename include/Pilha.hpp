#ifndef PILHA_H
#define PILHA_H

#include <iostream>

const int MAXTAM = 1000;

template <class T>
class Pilha {
    private:
        int _tamanho;
        int _topo;
        T _itens[MAXTAM];
        
    public:
        Pilha() {
            this->_tamanho = 0;
            this->_topo = -1;
        }

        void Empilha(T item) {
            this->_tamanho++;
            this->_topo++;
            this->_itens[_topo] = item;
        }

        T Desempilha() {
            T UltimoItem = this->_itens[_topo];
            this->_tamanho--;
            this->_topo--;
            return UltimoItem;

        }

        void Limpa() {
            if (this->EstaVazia()) {
                std::cout << "ERRO PILHA ESTÁ VAZIA" << "\n";
                return;
            }
            this->_tamanho = 0;
            this->_topo = -1;
        }

        bool EstaVazia() {
            if (this->_tamanho == 0) return true;
            else return false;
        }

        T VerTopo() {
            if (this->EstaVazia()) {
                std::cout << "ERRO PILHA ESTÁ VAZIA" << "\n";
            }
            T UltimoValor = this->_itens[_topo];
            return UltimoValor;
        }
    
};

#endif