#include "PersistenciaDeRede.h"
#include "Roteador.h"
#include "Rede.h"
#include "Hospedeiro.h"
#include "No.h"
#include<fstream>
#include<stdexcept>

PersistenciaDeRede::PersistenciaDeRede()
{
    //ctor
}

PersistenciaDeRede::~PersistenciaDeRede()
{
    //dtor
}

Rede* PersistenciaDeRede::carregar(string arquivo){

    Rede *rede = new Rede();

    ifstream input;
    input.open(arquivo.c_str());

    if(input.fail()){
        input.close();
        throw new invalid_argument("Arquivo nao encontrado");
    }

    //cout << "Abri o arquivo" << endl; OK

    //leitura dos roteadores
    int quantidadeRoteadores;
    input >> quantidadeRoteadores;
    for (int i = 0; input && i < quantidadeRoteadores; i++){
        int enderecoRoteador;
        input >> enderecoRoteador;
        Roteador* novoRoteador = new Roteador(enderecoRoteador);
        rede->adicionar(novoRoteador);
    }
    //cout << "Adicionei os roteadores" << endl; OK

    //leitura dos hospedeiros
    int quantidadeHospedeiros;
    input >> quantidadeHospedeiros;
    for(int i = 0; input && i < quantidadeHospedeiros; i++){
        int enderecoHospedeiro, enderecoGateway, quantidadeDeProcessos;
        input >> enderecoHospedeiro;
        input >> enderecoGateway;
        input >> quantidadeDeProcessos;

        No* recuperandoRoteador = rede->getNo(enderecoGateway);
        Roteador* gateway = dynamic_cast<Roteador*>(recuperandoRoteador);
        Hospedeiro* novoHospedeiro = new Hospedeiro(enderecoHospedeiro, gateway);

        //Leitura dos processos de um hospedeiro
        for(int j = 0; input && j < quantidadeDeProcessos; j++){

            char tipoProcesso;
            input >> tipoProcesso;
            int porta;
            //se for um ServidorWeb
            if(tipoProcesso == 'w'){
                string conteudo;
                input >> porta;
                input >> conteudo;
                try{
                    novoHospedeiro->adicionarServidorWeb(porta,conteudo);
                }catch(logic_error *e){
                    cout << "Erro: " << e->what() << endl;
                }

            }//se for um Navegador
            else if(tipoProcesso == 'n'){

                input >> porta;
                try{
                    novoHospedeiro->adicionarNavegador(porta);
                }catch(logic_error *e){
                    cout << "Erro:" << e->what() << endl;
                    delete e;
                }
                //cout << porta << endl;
            }
        }
        rede->adicionar(novoHospedeiro);
    }
    //cout << "Adicionei os hospedeiros" << endl; OK

    //Leitura das tabelas de repasse de cada roteador
    for(int i = 0; i < quantidadeRoteadores; i++){
        int enderecoRoteadorAtual, enderecoRoteadorPadrao, quantidadeMapeamentos;
        input >> enderecoRoteadorAtual;
        input >> enderecoRoteadorPadrao;
        input >> quantidadeMapeamentos;

        No* recuperandoRoteadorPadrao = rede->getNo(enderecoRoteadorPadrao);
        Roteador* roteadorPadrao = dynamic_cast<Roteador*>(recuperandoRoteadorPadrao);

        No* recuperandoRoteadorAtual = rede->getNo(enderecoRoteadorAtual);
        Roteador* roteadorAtual = dynamic_cast<Roteador*>(recuperandoRoteadorAtual);

        roteadorAtual->getTabela()->setPadrao(roteadorPadrao);

        //Leitura de cada mapeamento da tabela de repasses
        for (int j = 0; j < quantidadeMapeamentos; j++){
            int enderecoAMapear, noDestino;
            input >> enderecoAMapear;
            input >> noDestino;
            roteadorAtual->getTabela()->mapear(enderecoAMapear, rede->getNo(noDestino));


        }
    }

    if(!input.eof()){
        input.close();
        throw new invalid_argument("Erro de leitura");
    }

    if(quantidadeRoteadores == 0){
        input.close();
        throw new invalid_argument("Arquivo vazio");
    }

    input.close();
    return rede;
}

