#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador *gateway) : Processo(endereco, porta, gateway)
{
  this->conteudo = "";
}

Navegador::~Navegador()
{
}

void Navegador::abrir(int endereco, int porta)
{

  Segmento *dado = new Segmento(this->porta, porta, "GET");
  Datagrama *getRequest = new Datagrama(this->endereco, endereco, Processo::getTtlPadrao(), dado);

  gateway->receber(getRequest);
  //nao deletar
  //delete dado, getRequest;

  this->conteudo = "";
}

void Navegador::abrir(int endereco)
{
  Segmento *dado = new Segmento(this->porta, 80, "GET");
  Datagrama *getRequest = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), dado);

  this->gateway->receber(getRequest);
  //nao deletar
  //delete dado, getRequest;

  this->conteudo = "";
}

string Navegador::getConteudo()
{
  return this->conteudo;
}

void Navegador::receber(int origem, Segmento *mensagem)
{
  if (this->conteudo == "")
  {
    this->conteudo = mensagem->getDado();

    cout << "Navegador " << this->porta << endl;
    //cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeDestino() << ": " << this->conteudo << endl;
    cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << this->conteudo << endl;
  }
  else
  {
    cout << "Navegador " << this->porta << endl;
    //cout << "\tMensagem ignorada " << origem << ":" << mensagem->getPortaDeDestino() << ": " << this-> conteudo << endl;
    cout << "\tMensagem ignorada " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << this-> conteudo << endl;
  }
}
