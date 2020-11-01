#include <iostream>
#include "Segmento.h"
#include "datagrama.h"
using namespace std;

int main()
{
    Segmento *s = new Segmento(1,2,"Oi");
    s->imprimir();
    Datagrama *d = new Datagrama(1,3,4,s);
    d->imprimir();
    return 0;

}
