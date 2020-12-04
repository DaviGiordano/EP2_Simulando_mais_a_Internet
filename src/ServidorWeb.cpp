#include "ServidorWeb.h"

#include <iostream>
using namespace std;

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo)
 : Processo(endereco,porta,gateway){

    this->conteudo = conteudo;
}

ServidorWeb::~ServidorWeb()
{

}
void ServidorWeb::receber(int origem, Segmento* mensagem){

    Segmento* dado = new Segmento(this->porta, mensagem->getPortaDeOrigem(), this->conteudo);
    Datagrama* resposta = new Datagrama(this->endereco,origem,Processo::getTtlPadrao(), dado);

    gateway->receber(resposta);
    cout << "ServidorWeb " << this->porta << endl;

    cout << "\tDevolvendo mensagem para: " << origem << ":" << mensagem->getPortaDeOrigem() << endl;

}
