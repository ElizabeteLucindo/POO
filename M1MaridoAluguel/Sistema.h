#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cliente.h"
#include "TrabalhadorEspecifico.h"
#include "Contrato.h"


class Sistema{
private:
Contrato contratos[MAX] = {}; // Array para armazenar os contratos
Cliente clientes[MAX];
Trabalhador trabalhadores[MAX];
int numClientes = 0;
int numTrabalhadores = 0;
int numContratos = 0;

public:
  Sistema();
  void contratarServico(Trabalhador trabalhador, Cliente cliente, const string data);
  bool imprimirContratos(Cliente cliente);
  void cadastrarCliente(Cliente cliente);
  void cadastrarTrabalhador(Trabalhador trabalhador);
  void imprimeListaClientes();
  void imprimeListaTrabalhadores();
};

Sistema::Sistema(){}

void Sistema::contratarServico(Trabalhador trabalhador, Cliente cliente, const string data) {
    bool disponivel = true;

    // Verificar se o trabalhador já tem um serviço agendado para a data especificada
    for (int i = 0; i < numContratos; i++) {
        if (contratos[i].getTrabalhador() == trabalhador && contratos[i].getData() == data) {
            disponivel = false;
            break;
        }
    }

    if (disponivel) {
        // Se o trabalhador estiver disponível, contratar o serviço
        contratos[numContratos] = Contrato(trabalhador, cliente, data);
        trabalhador.adicionarServico(data); // Marcar o trabalhador como ocupado nesta data
        numContratos++;
        cout << "Serviço contratado com sucesso para o dia " << data << endl;
    } else {
        cout << "Desculpe, o trabalhador não está disponível para essa data." << endl;
    }
}

bool Sistema::imprimirContratos(Cliente cliente) {
  for (int i = 0; i < numContratos; i++) {
    if (contratos[i].getCliente() == cliente) {
      cout << "\nCONTRATO " << endl;
      cout << "\nTrabalhador: " << endl;
      contratos[i].getTrabalhador().imprime();
  
      cout << "\nCliente: " << endl;
      contratos[i].getCliente().imprime();
  
      cout << "\nData do contrato: " << contratos[i].getData() << endl;
      return true;
    }
  }
  cout << "Contrato não encontrado." << endl;
  return false;
}

void Sistema::cadastrarCliente(Cliente cliente) {
  if (numClientes < MAX) {
    clientes[numClientes] = cliente;
    numClientes++;
  }
}

void Sistema::cadastrarTrabalhador(Trabalhador trabalhador) {
  if (numTrabalhadores < MAX) {
    trabalhadores[numTrabalhadores] = trabalhador;
    numTrabalhadores++;
  }
}

void Sistema::imprimeListaClientes() {
  cout << "Lista de Clientes" << endl << endl;
  for (int i = 0; i < numClientes; ++i) {
    cout << "Nome: " << clientes[i].getNome() << endl;
    cout << "Endereço: " << clientes[i].getEndereco() << endl;
    cout << "Telefone: " << clientes[i].getTelefone() << endl << endl;
  }
}

void Sistema::imprimeListaTrabalhadores() {
  cout << "Lista de Trabalhadores" << endl << endl;
  for (int i = 0; i < numTrabalhadores; ++i) {
    cout << "Nome: " << trabalhadores[i].getNome() << endl;
    cout << "Endereço: " << trabalhadores[i].getEndereco() << endl;
    cout << "Telefone: " << trabalhadores[i].getTelefone() << endl;
    cout << "Profissão: " << trabalhadores[i].getProfissao() << endl << endl;
  }
}

#endif