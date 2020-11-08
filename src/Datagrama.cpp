#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, int ttl, Segmento *dado)
{
    this->origem = origem;
    this->destino = destino;
    this->ttl = ttl;
    this->dado = dado;
}

Datagrama::~Datagrama()
{
    delete dado;
}

int Datagrama::getOrigem(){
    return this->origem;
}

int Datagrama::getDestino(){
    return this->destino;
}
int Datagrama::getTtl(){
    return this->ttl;
}
Segmento* Datagrama::getDado(){
    return this->dado;
}

void Datagrama::processar(){
    this->ttl -= 1;
}

bool Datagrama::ativo(){
    return (this->getTtl() > 0);
}

void Datagrama::imprimir(){
    cout << "Origem: "
        << this->origem
        << ":"
        << this->dado->getPortaDeOrigem()
        << ", Destino: "
        << this->destino
        << ":"
        << this->dado->getPortaDeDestino()
        << ",TTL: "
        << this->ttl
        << ", "
        << this->dado->getDado()
        << endl;
}
