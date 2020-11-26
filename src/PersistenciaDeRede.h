#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include "Rede.h"
class PersistenciaDeRede
{
public:
    PersistenciaDeRede();
    virtual ~PersistenciaDeRede();
    virtual Rede* carregar(string arquivo);
};

#endif // PERSISTENCIADEREDE_H
