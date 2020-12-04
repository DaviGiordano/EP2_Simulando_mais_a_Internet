#include "Hospedeiro.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway) : No(endereco), gateway(gateway)
{
    //ctor
}

Hospedeiro::~Hospedeiro()
{
    //basta fazer delete[] processos? Ou isso so destroi o vector e nao cada processo?
    for(unsigned int i = 0; i < processos->size(); i++) {
        delete (*processos)[i];
    }
}

//Adiciona um ServidorWeb ao vector de processos, joga um logic_error se for repetido
void Hospedeiro::adicionarServidorWeb(int porta, string conteudo){

    Processo* novoProcesso = new ServidorWeb(this->endereco, porta, this->gateway, conteudo);

    for(unsigned int i = 0; i < processos->size(); i++) {
        if((*processos)[i] == novoProcesso) throw new logic_error("Processo ja adicionado");
    }

    processos->push_back(novoProcesso);
}

//Adiciona um Navegador ao vector de processos, joga um logic_error se for repetido
void Hospedeiro::adicionarNavegador(int porta){
    Processo* novoProcesso = new Navegador(this->endereco,porta,this->gateway);

    for(unsigned int i = 0; i < processos->size(); i++) {
        if((*processos)[i] == novoProcesso) throw new logic_error("Processo ja adicionado");
    }

    processos->push_back(novoProcesso);
}

//Retorna um processo com a porta pedida do vector de processos do Hospedeiro
Processo* Hospedeiro::getProcesso(int porta){

    for(unsigned int i = 0; i < processos->size(); i++) {
        if((*processos)[i]->getPorta() == porta) return (*processos)[i];
    }
    return NULL;
}
vector<Processo*>* Hospedeiro::getProcessos(){
    return processos;
}

//Processsa um datagrama da fila do Hospedeiro, repassando-o para o processo (porta) de destino
//captura um underflow_error da fila do datagrama
void Hospedeiro::processar(){

    try{
        int encontreiProcesso = 0;
        Datagrama* datagramaAtual = this->fila->dequeue();
        for(unsigned int i = 0; i < processos->size(); i++) {
            if((*processos)[i]->getPorta() == datagramaAtual->getDado()->getPortaDeDestino()){
                encontreiProcesso = 1;
                (*processos)[i]->receber(datagramaAtual->getOrigem(), datagramaAtual->getDado());
            }
        }
        if(!encontreiProcesso){
            cout << "Sem destino: " << endl;
            datagramaAtual->imprimir();
        }
        delete datagramaAtual;
    }catch(underflow_error *e){
        //cout << "Erro: " << e->what() << endl;
    }
}
