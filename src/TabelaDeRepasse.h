#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

//#include "No.h"

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

    //definimos o valor da tabela aqui ou no cpp?
    static const int MAXIMO_TABELA = 5;

private:
    int quantidadeDeAdjacentes = 0;
    int *enderecos;
    No **adjacentes;
    No *padrao;

};

#endif // TABELADEREPASSE_H
