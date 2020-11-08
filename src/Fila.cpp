#include "Fila.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Inicializa a fila e constroi um vetor de datagramas com espaço tamanho
Fila::Fila(int tamanho) :
tamanho (tamanho)
{
    this->vetorDeDatagramas = new Datagrama *[this->tamanho + 1];
}

Fila::~Fila()
{
    delete[] this->vetorDeDatagramas;
}

// Adiciona um datagrama na fila. Se a fila estiver cheia, joga um overflow_error
void Fila::enqueue(Datagrama *d) {

        // condicao para fila cheia
    if ( (this->inicio == 0 && this->fim == this->tamanho ) || this->fim + 1 == this->inicio) {
        throw new overflow_error("Fila cheia");
    }

    // caso contrario, adiciona datagrama no fim da fila
    this->vetorDeDatagramas[this->fim] = d;

    // e atualiza o valor de fim
    if (this->fim == this->tamanho) {
            this->fim = 0;
    } else  {
            this->fim += 1;
    }

}

// Retorna true caso a fila estiver cheia e false caso contrario
bool Fila::isEmpty() {
    return this->inicio == this->fim;
}


// Retira um datagrama da fila. Se a fila estiver vazia, joga um underflow_error
Datagrama* Fila::dequeue(){

    if(this->isEmpty()){
        throw new underflow_error("Fila vazia");
    }

    // TIRAR O DATAGRAMA
    Datagrama* datagramaRetirado = this->vetorDeDatagramas[this->inicio];
    if(this->inicio == this->tamanho){
        this->inicio = 0;
    } else {
        this->inicio += 1;
    }
    return datagramaRetirado;

}

void Fila::imprimir(){
    cout << endl << "== FILA IMPRIMIR ==" << endl << endl;
    cout << "\ttamanho disponivel - " << this->tamanho << endl << endl;
    cout << "\tinicio - " << this->inicio << endl << endl;
    cout << "\tfim - " << this->fim << endl << endl;
    cout <<  "\tFila, na ordem:" << endl << endl;

    for(int i = this->inicio; i != (this->fim);){

        cout <<"\tPosicao " << i << " no vetor: ";
        vetorDeDatagramas[i]->imprimir();

        if(i == this->tamanho){
            i = 0;
        }
        else{
            i++;
        }
    }
    cout << endl << "== FIM FILA IMPRIMIR ==" << endl << endl;

}
