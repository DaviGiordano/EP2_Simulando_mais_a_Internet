#include "Processo.h"

Processo::Processo(int endereco, int porta, Roteador* gateway)
{
    this->endereco = endereco;
    this->porta = porta;
    this->gateway = gateway;
}

Processo::~Processo()
{
}
/*
static void Processo::setTtlPadrao(int padrao){
    Processo::ttlPadrao = padrao;
}

static int Processo::getTtlPadrao(){
    return Processo::ttlPadrao;
}
*/

int Processo::getEndereco(){
    return this->endereco;
}

int Processo::getPorta(){
    return this->porta;
}
