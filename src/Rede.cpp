#include "Rede.h"

Rede::Rede() {
  this->nos = new No *[20];
  this->quantidadeDeNos = 0;
}

Rede::~Rede() {
    //aqui temos que destruir individualmente cada no??
  delete[] this->nos;
}

// O  método adicionar  deve  adicionar  o No  à Rede.
// Caso  já  exista  um No  na Rede  com  o  mesmo endereço, jogue um logic_error (da biblioteca padrão) – e não adicione o No.
void Rede::adicionar(No *no) {
  for (int i = 0; i < this->quantidadeDeNos; i++) {
    if (this->nos[i] == no) throw new logic_error("Este no ja foi adicionado");
  }

  this->nos[this->quantidadeDeNos] = no;
  this->quantidadeDeNos += 1;
}

// getNo deve retornar o No que possui o endereço informado ou NULL caso não haja No na Rede com esse endereço
No* Rede::getNo(int endereco) {
  No *no = NULL;

  for (int i = 0; i < this->quantidadeDeNos; i++) {
    if (this->nos[i]->getEndereco() == endereco) no = this->nos[i];
  }

  return no;
}

// Retorna uma list de hospedeiros dentro da Rede
list<Hospedeiro*>* Rede::getHospedeiros() {
  list<Hospedeiro*> *l = new list<Hospedeiro*>();

  for (int i = 0; i < this->quantidadeDeNos; i++) {
    Hospedeiro *h = dynamic_cast<Hospedeiro*>(nos[i]);
    if(h != NULL){
        l->push_back(h);
    }
  }

  return l;
}

  // virtual void passarTempo();
void Rede::passarTempo() {
  for (int i = 0; i < this->quantidadeDeNos; i++) {
    this->nos[i]->processar();
  }
}

void Rede::imprimir() {
}
