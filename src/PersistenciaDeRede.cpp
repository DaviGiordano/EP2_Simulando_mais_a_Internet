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
    input.open("arquivocstr", ios_base::in);

    if(input.fail()){
        input.close();
        throw new invalid_argument("Arquivo nao encontrado");
    }

    //leitura dos roteadores
    int quantidadeRoteadores;
    input >> quantidadeRoteadores;
    for (int i = 0; input && i < quantidadeRoteadores; i++){
        int enderecoRoteador;
        input >> enderecoRoteador;
        Roteador* novoRoteador = new Roteador(enderecoRoteador);
        rede->adicionar(novoRoteador);
    }

    //leitura dos hospedeiros
    int quantidadeHospedeiros;
    input >> quantidadeHospedeiros;
    for(int i = 0; input && i < quantidadeHospedeiros; i++){
        int enderecoHospedeiro, enderecoGateway, quantidadeDeProcessos;
        input >> enderecoHospedeiro;
        input >> enderecoGateway;
        input >> quantidadeDeProcessos;

            // ELE NAO ESTA ME DEIXANDO COLOCAR UM NOH No LUGAR DO ROTEADOR* GATEWAY :/
        Hospedeiro* novoHospedeiro = new Hospedeiro(enderecoHospedeiro, rede->getNo(enderecoGateway));

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
                novoHospedeiro->adicionarServidorWeb(porta,conteudo);

            }//se for um Navegador
            else if(tipoProcesso == 'n'){
                input >> porta;
                novoHospedeiro->adicionarNavegador(porta);
            }
        }
        //Leitura das tabelas de repasse de cada roteador
        for(int i; i < quantidadeRoteadores; i++){
            int enderecoRoteadorAtual, enderecoRoteadorPadrao, quantidadeMapeamentos;
            input >> enderecoRoteadorAtual;
            input >> enderecoRoteadorPadrao;
            input >> quantidadeMapeamentos;
            //ELE NAO ESTA ME DEIXANDO CONVERTER DE NO PARA ROTEADOR :/
            Roteador* roteadorAtual = rede->getNo(enderecoRoteadorAtual);
            roteadorAtual->getTabela()->setPadrao(rede->getNo(enderecoRoteadorPadrao));
            //Leitura de cada mapeamento da tabela de repasses
            for (int j; j < quantidadeMapeamentos; j++){
                int enderecoAMapear, noDesitino;
                input >> enderecoAMapear;
                input >> noDesitino;
                roteadorAtual->getTabela()->mapear(enderecoAMapear, rede->getNo(noDesitino));
            }

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
}

