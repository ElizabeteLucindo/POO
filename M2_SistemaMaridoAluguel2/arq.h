#ifndef ARQ_H
#define ARQ_H

#include "Sistema.h"
#include "TAD_Lista.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

void escrita_arq(TListaE<Trabalhador> &lista_tr, TListaE<Cliente> &lista_cl,
                 TListaE<Contrato> &lista_contrato,
                 TListaE<Trabalhador> &lista_trab_disp) {
  ofstream PROD("list.txt", ios::out); // Abre/cria o arquivo em modo de adição
  if (!PROD.is_open()) {
    cout << "Não foi possível abrir o arquivo para escrita." << endl;
    return;
  }

  /// Adiciona os dados dos trabalhadores
  if (lista_tr.inicio != NULL) {
    PROD << "Lista de Trabalhadores" << endl;
    PROD << "Nome\tEndereço\tCPF\tTelefone\tProfissão\tExperiência" << endl;
    TElemento<Trabalhador> *nav_tr =
        lista_tr.inicio; // Aponta para o início da lista

    while (nav_tr != NULL) { // Percorre a lista até chegar no final
      PROD << nav_tr->dado.getNome() << "\t" // setw para alinhado no txt
           << nav_tr->dado.getEndereco() << "\t"
           << nav_tr->dado.getCpf() << "\t"
           << nav_tr->dado.getTelefone() << "\t"
           << nav_tr->dado.getProfissao() << "\t"
           << nav_tr->dado.getExperiencia() << endl;

      nav_tr = nav_tr->proximo;
    }
    PROD << "------------------------------------------------------------"
         << endl;
  }

  /// Adiciona os dados dos clientes
  if (lista_cl.inicio != NULL) {
    PROD << "Lista de Clientes" << endl;
    PROD << "Nome\tEndereço\tCPF\tTelefone\tTarefa\t\tFormas de Pagamento"
         << endl;
    TElemento<Cliente> *nav_cl = lista_cl.inicio;

    while (nav_cl != NULL) { // Percorre a lista até chegar no final
      PROD  << nav_cl->dado.getNome() << "\t"
            << nav_cl->dado.getEndereco()<< "\t"
            << nav_cl->dado.getCpf() << "\t"
            << nav_cl->dado.getTelefone() << "\t"
            << nav_cl->dado.getTarefa()<< "\t"
            << nav_cl->dado.getFormaPagamento() << endl;

      nav_cl = nav_cl->proximo;
    }
    PROD << "------------------------------------------------------------"
         << endl;
  }

  /// Adiciona os dados do contratos
  if (lista_contrato.inicio != NULL) {
    PROD << "Lista de Contratos" << endl;
    TElemento<Contrato> *nav_contrato = lista_contrato.inicio;

    while (nav_contrato != NULL) { // Percorre a lista até chegar no final
      PROD << "Contrato" << endl;
      PROD << "Trabalhador: " << endl;
      PROD << nav_contrato->dado.getTrabalhador().getNome() << "\t"
           << nav_contrato->dado.getTrabalhador().getEndereco() << "\t"
           << nav_contrato->dado.getTrabalhador().getCpf() << "\t"
           << nav_contrato->dado.getTrabalhador().getTelefone() << "\t"
           << nav_contrato->dado.getTrabalhador().getProfissao() << "\t"
           << nav_contrato->dado.getTrabalhador().getExperiencia() << endl;

      PROD << "Cliente: " << endl;
      PROD << nav_contrato->dado.getCliente().getNome() << "\t"
           << nav_contrato->dado.getCliente().getEndereco() << "\t"
           << nav_contrato->dado.getCliente().getCpf() << "\t"
           << nav_contrato->dado.getCliente().getTelefone() << "\t"
           << nav_contrato->dado.getCliente().getTarefa() << "\t"
           << nav_contrato->dado.getCliente().getFormaPagamento() << endl;

      PROD << "Data do contrato: " << nav_contrato->dado.getData() << endl;
      nav_contrato = nav_contrato->proximo;
    }
    PROD << "------------------------------------------------------------"
         << endl;
  }

  /// Adiciona os dados do lista disponiveis
  if (lista_trab_disp.inicio != NULL) {
    PROD << "Lista de Trabalhadores Disponíveis" << endl;
    TElemento<Trabalhador> *nav_trab_disp =
        lista_trab_disp.inicio; // Aponta para o início da lista

    while (nav_trab_disp != NULL) { /// Percorre a lista até chegar no final
      PROD << nav_trab_disp->dado.getNome() << "\t" // setw para alinhado no txt
           << nav_trab_disp->dado.getEndereco() << "\t"
           << nav_trab_disp->dado.getCpf() << "\t"
           << nav_trab_disp->dado.getTelefone() << "\t"
           << nav_trab_disp->dado.getProfissao() << "\t"
           << nav_trab_disp->dado.getExperiencia() << endl;

      nav_trab_disp = nav_trab_disp->proximo;
    }
    PROD << "------------------------------------------------------------"
         << endl;
  }

  PROD.close(); // Fecha o arquivo
}

void leitura_arq(TListaE<Trabalhador> &lista_tr, TListaE<Cliente> &lista_cl,
                 TListaE<Contrato> &lista_contrato,
                 TListaE<Trabalhador> &lista_trabalhador_disponivel) {
  ifstream PRODUCT("list.txt"); // Abre o arquivo
  if (!PRODUCT.is_open()) {
    cout << "Não foi possível abrir o arquivo para leitura." << endl;
    return;
  }

  Trabalhador novo_trabalhador;
  Cliente novo_cliente;
  Contrato novo_contrato;

  string line;
  bool is_trabalhadores = false;
  bool is_clientes = false;
  bool is_contratos = false;
  bool is_trab_disp = false;

  while (getline(PRODUCT, line)) { // Enquanto houver linhas para ler
    if (line.empty())
      continue; // Ignora linhas em branco

    if (line == "Lista de Trabalhadores") {
      is_trabalhadores = true;
      is_clientes = false;
      is_contratos = false;
      is_trab_disp = false;
      getline(PRODUCT, line); // Ignora o cabeçalho
      continue;
    } else if (line == "Lista de Clientes") {
      is_trabalhadores = false;
      is_clientes = true;
      is_contratos = false;
      is_trab_disp = false;
      getline(PRODUCT, line); // Ignora o cabeçalho
      continue;
    } else if (line == "Lista de Contratos") {
      is_trabalhadores = false;
      is_clientes = false;
      is_contratos = true;
      is_trab_disp = false;
      getline(PRODUCT, line); // Ignora o cabeçalho
      continue;
    } else if (line == "Lista de Trabalhadores Disponíveis") {
      is_trabalhadores = false;
      is_clientes = false;
      is_contratos = false;
      is_trab_disp = true;    // Define como true ao encontrar a lista correta
      getline(PRODUCT, line); // Ignora o cabeçalho
      continue;
    } else if (line ==
               "------------------------------------------------------------") {
      continue; // Ignora linhas separadoras
    }

    // Separe os dados da linha
    stringstream ss(line);
    string nome, endereco, profissao, experiencia, tarefa, formaPagamento;
    long long int cpf;
    int telefone;

    if (is_trabalhadores) {
      getline(ss, nome, '\t');
      getline(ss, endereco, '\t');
      ss >> cpf >> telefone;
      ss.ignore();
      getline(ss, profissao, '\t');
      getline(ss, experiencia);

      novo_trabalhador.setNome(nome);
      novo_trabalhador.setEndereco(endereco);
      novo_trabalhador.setCpf(cpf);
      novo_trabalhador.setTelefone(telefone);
      novo_trabalhador.setProfissao(profissao);
      novo_trabalhador.setExperiencia(experiencia);
      insere_fim(lista_tr, novo_trabalhador);
    } else if (is_clientes) {

      getline(ss, nome, '\t');
      getline(ss, endereco, '\t');
      ss >> cpf >> telefone;
      ss.ignore();
      getline(ss, tarefa, '\t');
      getline(ss, formaPagamento);

      novo_cliente.setNome(nome);
      novo_cliente.setEndereco(endereco);
      novo_cliente.setCpf(cpf);
      novo_cliente.setTelefone(telefone);
      novo_cliente.setTarefa(tarefa);
      novo_cliente.setFormaPagamento(formaPagamento);
      insere_fim(lista_cl, novo_cliente);

    } else if (is_contratos) {
      string trabalhadorNome, clienteNome;
      string data;

      // Leia os dados do trabalhador
      getline(ss, trabalhadorNome, '\t');
      getline(ss, endereco, '\t');
      ss >> cpf; // Corrigido para ler corretamente o CPF
      ss.ignore();
      ss >> telefone; // Corrigido para ler corretamente o telefone
      ss.ignore();
      getline(ss, profissao, '\t');
      getline(ss, experiencia, '\t');

      // Leia os dados do cliente
      getline(ss, clienteNome, '\t');
      getline(ss, endereco, '\t');
      ss >> cpf; // Corrigido para ler corretamente o CPF
      ss.ignore();
      ss >> telefone; // Corrigido para ler corretamente o telefone
      ss.ignore();
      getline(ss, tarefa, '\t');
      getline(ss, formaPagamento);

      // Leia a data do contrato
      getline(ss, data);

      // Crie um novo trabalhador com os dados lidos
      Trabalhador contratado(trabalhadorNome, endereco, cpf, telefone,
                             profissao, experiencia);

      // Crie um novo cliente com os dados lidos
      Cliente cliente(clienteNome, endereco, cpf, telefone, tarefa,
                      formaPagamento);

      // Crie um novo contrato com os dados lidos e adicione à lista de
      // contratos
      Contrato novo_contrato(contratado, cliente, data);
      insere_fim(lista_contrato, novo_contrato);

    } else if (line == "Lista de Trabalhadores Disponíveis") {
      is_trabalhadores = false;
      is_clientes = false;
      is_contratos = false;
      is_trab_disp = true;    // Define como true ao encontrar a lista correta
      getline(PRODUCT, line); // Ignora o cabeçalho

      while (getline(PRODUCT, line)) { // Enquanto houver linhas para ler
        if (line.empty())
          continue; // Ignora linhas em branco

        Trabalhador novo_trab_disponivel;
        // Separa os dados da linha
        stringstream ss(line);
        string nome, endereco, profissao, experiencia;
        long long int cpf;
        int telefone;
        getline(ss, nome, '\t');
        getline(ss, endereco, '\t');
        ss >> cpf >> telefone;
        ss.ignore();
        getline(ss, tarefa, '\t');
        getline(ss, formaPagamento);

        novo_trab_disponivel.setNome(nome);
        novo_trab_disponivel.setEndereco(endereco);
        novo_trab_disponivel.setCpf(cpf);
        novo_trab_disponivel.setTelefone(telefone);
        novo_trab_disponivel.setProfissao(profissao);
        novo_trab_disponivel.setExperiencia(experiencia);

        insere_fim(lista_trabalhador_disponivel, novo_trab_disponivel);
      }
    }
  }

  PRODUCT.close(); // Fecha o arquivo
}

#endif
