#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H

#include "Processo.h"


class ServidorWeb : public Processo
{
    public:
        ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
        virtual ~ServidorWeb();
        virtual void receber(int origem, Segmento* mensagem);

    protected:

    private:
        string conteudo;
};

#endif // SERVIDORWEB_H
