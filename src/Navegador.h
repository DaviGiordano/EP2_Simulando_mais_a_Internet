#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Processo.h"
#include <string>

class Navegador : public Processo {
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();

        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);

        virtual string getConteudo();

    protected:

    private:
        string conteudo;
};

#endif // NAVEGADOR_H
