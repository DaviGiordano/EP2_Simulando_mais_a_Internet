#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"


class Fila
{
    public:
        Fila(int tamanho);
        virtual ~Fila();
        virtual void enqueue(Datagrama *d);
        virtual Datagrama *dequeue();
        virtual bool isEmpty();

        void imprimir();
    protected:

    private:
        int inicio = 0;
        int fim = 0;
        int tamanho;
        Datagrama **vetorDeDatagramas;
};

#endif // FILA_H
