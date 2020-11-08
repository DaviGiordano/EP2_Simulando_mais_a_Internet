#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "No.h"
#include "TabelaDeRepasse.h"

class Roteador : public No
{
    public:
        Roteador(int endereco);
        virtual ~Roteador();

        virtual TabelaDeRepasse* getTabela();
        virtual void processar();
    protected:

    private:
        TabelaDeRepasse* tabela;

};

#endif // ROTEADOR_H
