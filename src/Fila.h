#ifndef FILA_H
#define FILA_H


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
};

#endif // FILA_H
