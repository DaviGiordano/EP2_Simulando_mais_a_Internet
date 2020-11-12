#include "Roteador.h"


Roteador::Roteador(int endereco) : No(endereco) {
    this->tabela = new TabelaDeRepasse();
}

Roteador::~Roteador() {
    delete tabela;
}

TabelaDeRepasse* Roteador::getTabela() {
    return this->tabela;
}


void Roteador::processar() {
    try {
        //pode jogar um underflow_error:
        Datagrama* datagramaAtual = this->fila->dequeue();

        cout << "Roteador " << this->endereco << endl;
        datagramaAtual->processar();

        if(!datagramaAtual->ativo()) {
            cout << "\tDestruido por TTL: ";
            datagramaAtual->imprimir();
            delete datagramaAtual;
        }
        else if(datagramaAtual->getDestino() == this->endereco) {
            //tambem destruir
            cout << "\tRecebido: ";
            datagramaAtual->imprimir();
            delete datagramaAtual;
        }
        else {
            No* proximoNo = this->tabela->getDestino(datagramaAtual->getDestino());

            if(proximoNo != NULL) {
                cout << "\tEnviado para " << proximoNo->getEndereco() << ": ";
                datagramaAtual->imprimir();
                proximoNo->receber(datagramaAtual);
            }
            else {
                cout << "\tSemProximo: ";
                datagramaAtual->imprimir();
                delete datagramaAtual;
            }
        }


    }catch(underflow_error *e) {
        cout << "Error: " << e->what() << endl;
    }
}
