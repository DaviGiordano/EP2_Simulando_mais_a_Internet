#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"
#include <iostream>
#include <stdexcept>
using namespace std;

class TabelaDeRepasse
{
public:
    TabelaDeRepasse();
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();
    virtual void setPadrao(No *padrao);
    virtual No* getDestino(int endereco);
    virtual void imprimir();


private:
    static const int MAXIMO_TABELA;
    int quantidadeDeAdjacentes = 0;
    int *enderecos;
    No **adjacentes;
    No *padrao;

};

#endif // TABELADEREPASSE_H
