#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <exception>
#include "PilhaExcp.hpp"

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
            if (this->EstaVazia()) {
                throw PilhaExcp::PilhaVazia();
            }
            T UltimoItem = this->_itens[_topo];
            this->_tamanho--;
            this->_topo--;
            return UltimoItem;

        }

        void Limpa() {
            this->_tamanho = 0;
            this->_topo = -1;
        }

        bool EstaVazia() {
            if (this->_tamanho == 0) return true;
            else return false;
        }

        T VerTopo() {
            if (this->EstaVazia()) {
                throw PilhaExcp::PilhaVazia();
            }
            
            T UltimoValor = this->_itens[_topo];
            return UltimoValor;
        }
    
};

#endif