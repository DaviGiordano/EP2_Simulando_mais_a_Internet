#include <iostream>
#include "Segmento.h"

using namespace std;

int main()
{
    Segmento *s = new Segmento(1,2,"Oi");
    s->imprimir();
    return 0;
}
