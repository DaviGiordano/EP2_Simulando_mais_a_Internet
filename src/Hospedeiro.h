#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "No.h"
#include "Roteador.h"
#include "Processo.h"
#include "ServidorWeb.h"
#include "Navegador.h"
#include <string>
#include <vector>

class Hospedeiro : public No
{
    public:
        Hospedeiro(int endereco, Roteador* gateway);
        virtual ~Hospedeiro();

        virtual void adicionarServidorWeb(int porta, string conteudo);
        virtual void adicionarNavegador(int porta);

        virtual void processar();

        virtual Processo* getProcesso(int porta);
        virtual vector<Processo*>* getProcessos();

    private:
        Roteador* gateway;
        vector<Processo*>* processos = new vector<Processo*>();

};

#endif // HOSPEDEIRO_H
