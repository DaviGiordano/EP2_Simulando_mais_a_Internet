#include "No.h"

No::No(int endereco) : endereco(endereco)
{
    this->fila = new Fila(No::TAMANHO_FILA);

}

No::~No()
{
    delete fila;
}


Fila* No::getFila() {
    return this->fila;
}

int No::getEndereco() {
    return this->endereco;
}

// Adiciona um datagrama a fila caso ela nao esteja cheia, caso contrario, nao adiciona o datagrama
// e imprime uma mensagem de erro
void No::receber(Datagrama *d) {

    try{
        this->fila->enqueue(d);
    }catch(overflow_error *e){
        cout << "\tFila em " << this->endereco << " estourou" << endl;
    }

}

//processar nao deve ser implementada aqui, e sim nas classes filhas,
//pois eh um metodo abstrato

void No::imprimir() {
    cout << endl << "== NO IMPRIMIR ==" << endl << endl;
    cout << "\tEndereco: " << this->endereco;
    cout << "FILA:" << endl;
    this->fila->imprimir();

    cout << endl << "== FIM ROTEADOR IMPRIMIR ==" << endl;

}
