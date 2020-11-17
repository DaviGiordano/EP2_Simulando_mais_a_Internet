#include "Navegador.h"
#include "Datagrama.h"
#include "Segmento.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway) : Processo(endereco,porta,gateway){
    this->conteudo = "";
}

Navegador::~Navegador(){
}

void Navegador::abrir(int endereco, int porta){

    Segmento* dado = new Segmento(this->porta,porta,"GET");
    Datagrama* getRequest = new Datagrama(this->endereco, endereco, Processo::getTtlPadrao(), dado);

    gateway->receber(getRequest);

    this->conteudo = "";
}
void Navegador::abrir(int endereco){

    Segmento* dado = new Segmento(this->porta,80,"GET");
    Datagrama* getRequest = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), dado);

    gateway->receber(getRequest);

    this->conteudo = "";
}


string Navegador::getConteudo(){
    return this->conteudo;
}


void Navegador::receber(int origem, Segmento* mensagem){

}
