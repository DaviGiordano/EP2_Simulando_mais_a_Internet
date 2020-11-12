#include "Segmento.h"

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado)  {
    this->dado = dado;
    this->portaDeDestino = portaDeDestino;
    this->portaDeOrigem = portaDeOrigem;
}

Segmento::~Segmento() {
}

string Segmento::getDado() {
    return this->dado;
}

int Segmento::getPortaDeOrigem() {
    return this->portaDeOrigem;
}

int Segmento::getPortaDeDestino() {
    return this->portaDeDestino;
}

void Segmento::imprimir() {
    cout << "\tDado: "
    << this->dado
    << ", Porta de Origem: "
    << this->portaDeOrigem
    << ", Porta de Destino: "
    << this->portaDeDestino << endl;
}
