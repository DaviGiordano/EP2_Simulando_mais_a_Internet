#include <iostream>
#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include <string>
#include "Rede.h"
using namespace std;

int main()
{
    Rede* rede = new Rede();

    //criando os nos
    Roteador* r1 = new Roteador(1);
    Roteador* r2 = new Roteador(2);
    Roteador* r3 = new Roteador(3);
    Hospedeiro* h5 = new Hospedeiro(5,r3);
    Hospedeiro* h4 = new Hospedeiro(4,r1);

    //mapeando os enderecos
    r1->getTabela()->mapear(4,h4);
    r1->getTabela()->setPadrao(r2);
    r2->getTabela()->setPadrao(r1);
    r2->getTabela()->mapear(3,r3);
    r2->getTabela()->mapear(5,r3);
    r3->getTabela()->mapear(5,h5);

    rede->adicionar(r1);
    rede->adicionar(r2);
    rede->adicionar(r3);
    rede->adicionar(h4);
    rede->adicionar(h5);
    rede->imprimir();

}
