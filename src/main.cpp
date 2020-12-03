#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>

#include "Segmento.h"
#include "Datagrama.h"
#include "PersistenciaDeRede.h"
#include "Fila.h"
#include "Rede.h"
using namespace std;

Rede* obterRedeDeArquivo(string file);
int escolherTela();
void usarUmNavegador(Rede* rede);
void passarTempo(Rede* rede);
void alterarTTl();

int main()
{
    //obter dados da rede em formato de persistencia
    string fileName;
    cout << "Digite o nome do arquivo: ";
    cin >> fileName;

    Rede* rede = obterRedeDeArquivo(fileName);
    if (rede != NULL){
        int tela;

        do {
            tela = escolherTela();
            switch (tela)
            {
            case 1:
                usarUmNavegador(rede);
                break;
            case 2:
                passarTempo(rede);
                break;
            case 3:
                alterarTTl();
            default:
                break;
            }
        } while (tela != 4);

    }



}
//recebe o nome de um arquivo com dados sobre uma rede e tenta criar uma rede, pode pegar um erro do tipo invalid_argument
Rede* obterRedeDeArquivo(string file){
    PersistenciaDeRede* persistencia = new PersistenciaDeRede();
    Rede* rede;

    try{
        rede = persistencia->carregar(file);
        return rede;
    }catch(invalid_argument* e){
        cout << e->what();
        delete e;
        return NULL;
    }
}

int escolherTela(){
    int telaEscolhida;

    cout << "Simulador de Rede" << endl << "---" << endl;
    cout << "1) Usar um navegador" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Alterar TTL" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> telaEscolhida;

    return telaEscolhida;
}

void usarUmNavegador(Rede* rede){
    //usar um iterador para percorrer a lista de hospedeiros da Rede,
    //e em cada hospedeiro percorrer os processos, que é um vector

    list<Hospedeiro*>* hospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = hospedeiros->begin();

    while(i != hospedeiros ->end()){
        cout << "Hospedeiro " << (*i)->getEndereco() << endl;

        vector<Processo*>* processos = (*i)->getProcessos();

        for (unsigned int j = 0; j < processos->size(); j++){
            Processo* processoAtual = (*processos)[j];

            if(dynamic_cast<ServidorWeb*>(processoAtual) != NULL){
                cout << "\tServidorWeb " << processoAtual->getPorta() << endl;
            }
            else if(dynamic_cast<Navegador*>(processoAtual) != NULL){
                cout << "\tNavegador " << processoAtual->getPorta() << endl;
            }
        }
        i++;
    }

    //fazendo o uso do navegador em si
    int enderecoDoHospedeiro, portaDoNavegador, enderecoDaPagina, portaDoServidor;
    cout << "Digite o endereco do hospedeiro: ";
    cin >> enderecoDoHospedeiro;
    cout << "Digite a porta do navegador: ";
    cin >> portaDoNavegador;
    cout << "Abrir pagina no navegador: ";
    cin >> enderecoDaPagina;
    cout << "Porta do Servidor Web: ";
    cin >> portaDoServidor;

    Hospedeiro* hospedeiroAtual = dynamic_cast<Hospedeiro*>(rede->getNo(enderecoDoHospedeiro));

    if(hospedeiroAtual == NULL){
        cout << "Endereco invalido";
    }else{
        Navegador* navegadorAtual = dynamic_cast<Navegador*>(hospedeiroAtual->getProcesso(portaDoNavegador));

        if(navegadorAtual == NULL){
            cout << "Porta invalida";
        }else{
            navegadorAtual->abrir(enderecoDaPagina,portaDoServidor);
        }
    }


}

void passarTempo(Rede* rede){
    //PASSAR TEMPO E FAZER ALGUMAS IMPRESSOES
    /*
    int quantidadeDeTempo;
    cout << "Quantidade de tempo: ";
    cin >> quantidadeDeTempo;
    for(int i = 0; i < quantidadeDeTempo; i++){
        rede->passarTempo();
    }
    */
}

void alterarTTl(){
}
