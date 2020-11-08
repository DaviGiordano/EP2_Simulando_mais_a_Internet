#include "TabelaDeRepasse.h"
//#include "No.h"
#include <iostream>
#include <stdexcept>

using namespace std;
TabelaDeRepasse::TabelaDeRepasse()
{
    this->enderecos = new int[TabelaDeRepasse::MAXIMO_TABELA];
    this->adjacentes = new No*[TabelaDeRepasse::MAXIMO_TABELA];
    this->padrao = NULL; //ponteiro para no padrao apontando para NULL, check.
    //ctor
}

TabelaDeRepasse::~TabelaDeRepasse()
{
    delete[] this->adjacentes;
    delete[] this->enderecos;
}

No** TabelaDeRepasse::getAdjacentes() {
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return this->quantidadeDeAdjacentes;
}

void TabelaDeRepasse::setPadrao(No *padrao) {
    this->padrao = padrao;
}

// Retorna o No ligado ao endereco passado como parametro. Se o endereco nao estiver mapeado, retorna o No padrao
// Se a tabela ainda nao tiver No padrao nos seus atributos, retorna NULL
No* TabelaDeRepasse::getDestino(int endereco) {
    for (int i = 0; i < this->quantidadeDeAdjacentes; i++) {
        if (endereco == this->enderecos[i]) {
            return this->adjacentes[i];
        }
    }
    return this->padrao;
}

// Mapeia um roteador a um endereco na tabela de repasse. Caso for possivel mapear retorna true, caso contrario, false.
// Se o endereco ja estiver mapeado, altera o roteador ligado a ele, caso contrario, adiciona um endereco na tabela
void TabelaDeRepasse::mapear(int endereco, Roteador *adjacente) {

    //indicador de passagem
    int enderecoJaFoiMapeado = 0;

    if (this->quantidadeDeAdjacentes == TabelaDeRepasse::MAXIMO_TABELA) {
        throw new overflow_error("Tabela cheia");
    }

    // procura se esse endereco ja ta na tabela
    for (int i = 0; i < this->quantidadeDeAdjacentes; i++) {
        if (this->enderecos[i] == endereco){
            this->adjacentes[i] = adjacente;
            enderecoJaFoiMapeado = 1;
        }
    }

    // Se sobreviveu a esse for significa que o endereco nao esta mapeado, vamos mapea-lo
    if (!enderecoJaFoiMapeado){
        this->enderecos[this->quantidadeDeAdjacentes] = endereco;
        this->adjacentes[this->quantidadeDeAdjacentes] = adjacente;
        this->quantidadeDeAdjacentes += 1;
    }
}


void TabelaDeRepasse::imprimir(){
    cout << endl << "== TABELA DE REPASSE IMPRIMIR ==" << endl << endl;

    if(this->padrao != NULL){
        cout << "\tNo padrao: " << this->padrao->getEndereco() <<endl;
    }else{
        cout << "\tNo padrao: NULL" <<endl;
    }

    cout << "\tQuantidade de adjacentes: " << this->quantidadeDeAdjacentes << endl;
    cout << "\tNos Adjacentes: " << endl;
    for(int i = 0; i < this->quantidadeDeAdjacentes; i++){
        cout << "\tIndice: " << i << ", Endereco: " << this->enderecos[i] << endl;
    }
    cout << endl << "== FIM TABELA REPASSE IMPRIMIR ==" << endl << endl;
}
