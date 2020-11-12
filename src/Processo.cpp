#include "Processo.h"

int Processo::ttlPadrao = 5;

Processo::Processo(int endereco, int porta, Roteador* gateway) {
    this->endereco = endereco;
    this->porta = porta;
    this->gateway = gateway;
}

Processo::~Processo()
{
}

void Processo::setTtlPadrao(int padrao){
    Processo::ttlPadrao = padrao;
}

int Processo::getTtlPadrao(){
    return Processo::ttlPadrao;
}


int Processo::getEndereco(){
    return this->endereco;
}

int Processo::getPorta(){
    return this->porta;
}
