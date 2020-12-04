#ifndef NO_H
#define NO_H

#include "Fila.h"
#include <string>
#include <iostream>
using namespace std;
class No
{
    public:
        No(int endereco);
        virtual ~No();

        virtual Fila* getFila();
        virtual int getEndereco();

        //metodo abstrato
        virtual void processar() = 0;

        virtual void receber(Datagrama *d);

        virtual void imprimir();
        static const int TAMANHO_FILA;

    protected:
        Fila* fila;
        int endereco;

    private: 
        
};

#endif // NO_H
