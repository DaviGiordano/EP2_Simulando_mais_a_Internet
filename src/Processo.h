#ifndef PROCESSO_H
#define PROCESSO_H

#include "Segmento.h"
#include "Roteador.h"

//Sera ancenstral e abstrata
class Processo
{
    public:
        Processo(int endereco, int porta, Roteador* gateway);
        virtual ~Processo();

        virtual int getEndereco();
        virtual int getPorta();

        //metodo abstrato a ser definido no Navegador ou ServidorWeb
        virtual void receber(int origem, Segmento* mensagem) = 0;

        virtual void imprimir();

        static void setTtlPadrao(int padrao);
        static int getTtlPadrao();


    protected:
        int endereco;
        int porta;
        Roteador* gateway;

    private:
        static int ttlPadrao;

};

#endif // PROCESSO_H
