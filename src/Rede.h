#ifndef REDE_H
#define REDE_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <list>
#include "No.h"
#include "Hospedeiro.h"

class Rede
{
private:
  No **nos;
  int quantidadeDeNos;

public:
  Rede();
  virtual ~Rede();

  virtual void adicionar(No *no);
  virtual No *getNo(int endereco);
  virtual list<Hospedeiro *> *getHospedeiros();
  virtual void passarTempo();

  virtual void imprimir();
};

#endif