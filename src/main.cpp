#include <iostream>
#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include <string>

using namespace std;

int main()
{
    Segmento *s = new Segmento(1,2,"Oi");
    s->imprimir();
    Datagrama *d = new Datagrama(1,2,2,s);

    Fila *f = new Fila(1);
    try{
        f->dequeue();
        f->enqueue(d);
        f->enqueue(d);
    }catch(overflow_error *e){
        cout << "Erro: " << e->what() <<endl;
    }catch(underflow_error *e){
        cout << "Erro: " << e->what() << endl;
    }

}
