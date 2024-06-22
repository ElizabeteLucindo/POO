#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cliente.h"
#include "Contrato.h"
#include "TrabalhadorEspecifico.h"
#include "TAD_Lista.h"


class Sistema {
private:
    TListaE<Contrato> lista_contratos;
    TListaE<Trabalhador> lista_trabalhador;
    TListaE<Cliente> lista_cliente;
    TListaE<Trabalhador> lista_trabalhador_disponivel;

public:
    Sistema();
    void inicializa_listas();
    bool verificaDisponibilidade(Trabalhador trabalhador, string data);
    bool contratarServico(string nome_cliente, string nome_trabalhador,string data);
    bool cadastrar(); ///Cliente
    bool cadastrar(int escolha_funcao); ///Trabalhador
    void removerCliente(long long int cpf);
    void removerTrabalhador(long long int cpf);
    void pesquisaCliente(long long int cpf);
    void pesquisaTrabalhador(long long int cpf);
    void imprimeListaClientes();
    void imprimeListaTrabalhadores();
    void imprimeListaTrabalhadoresDisponiveis(string data);
    bool imprimirContratos(Cliente cliente);
    void editarCliente();
    TListaE<Contrato> &get_lista_contratos();
    TListaE<Trabalhador> &get_lista_trabalhador();
    TListaE<Cliente> &get_lista_cliente();
    TListaE<Trabalhador> &get_lista_trabalhador_disponivel();
};

Sistema::Sistema() {}


void Sistema::inicializa_listas() {
    inicializa_lista(lista_contratos);
    inicializa_lista(lista_trabalhador);
    inicializa_lista(lista_cliente);
    inicializa_lista(lista_trabalhador_disponivel);
}


bool Sistema::verificaDisponibilidade(Trabalhador trabalhador, string data){
    TElemento<Contrato> *nav =lista_contratos.inicio; /// início da lista de contratos
    while (nav != NULL) {       /// Percorre a lista de contratos
        if (nav->dado.getTrabalhador() == trabalhador && nav->dado.getData() == data) {
          return false; ///Já está ocupado
        }
    nav = nav->proximo; /// Avança para o próximo elemento na lista
    }
    return true;
}

bool Sistema::contratarServico(string nome_cliente, string nome_trabalhador,string data) {

    Cliente cliente = encontraPorNome(lista_cliente, nome_cliente);
    Trabalhador trabalhador = encontraPorNome(lista_trabalhador, nome_trabalhador);

    if (cliente.getNome() == "" && cliente.getEndereco() == "" && cliente.getCpf() == 0) {
        cout << "Cliente Inexistente" << endl;
        return false;
    }

    if (trabalhador.getNome() == "" && trabalhador.getEndereco() == "" && trabalhador.getCpf() == 0) {
        cout << "Trabalhador Inexistente" << endl;
        return false;
    }

    bool disponivel = true;

    disponivel = verificaDisponibilidade(trabalhador, data); ///Retorna true se está disponivel

  /// Se o trabalhador estiver disponível, contratar o serviço
  if (disponivel) {

    insere_fim(lista_contratos,Contrato(trabalhador, cliente, data)); /// Cria um contrato e insere na lista_contratos

    trabalhador.adicionarServico(data); /// Marcar o trabalhador como ocupado nesta data

    cout << "Serviço contratado com sucesso para o dia " << data << endl;
    return true;
  } else {
    cout << "Desculpe, o trabalhador não está disponível para essa data." << endl;
    return false;
  }
}

bool Sistema::imprimirContratos(Cliente cliente) {

  TElemento<Contrato> *nav = lista_contratos.inicio; /// início da lista de contratos
  while (nav != NULL) {       /// Percorre a lista de contratos
    if (nav->dado.getCliente() == cliente) {
      cout << "\nCONTRATO " << endl;
      cout << "\nTrabalhador: " << endl;
      nav->dado.getTrabalhador().imprime();

      cout << "\nCliente: " << endl;
      nav->dado.getCliente().imprime();

      cout << "\nData do contrato: " << nav->dado.getData() << endl;
      return true;
    }
    nav = nav->proximo; /// Avança para o próximo elemento na lista
  }
  cout << "Contrato não encontrado." << endl;
  return false;
}

bool Sistema::cadastrar() { /// Cadastrar para cliente
    string nome, endereco, formaPagamento, tarefa;
    long long int cpf, telefone;

    cout << "Nome: ";
    cin.ignore(); // Ignora o caractere de nova linha remanescente no buffer
    getline(cin, nome);

    cout << "Endereço: ";
    getline(cin, endereco);

    cout << "CPF: ";
    cin >> cpf;

    cout << "Telefone: ";
    cin >> telefone;
    cin.ignore();

    cout << "Forma de pagamento: ";
    getline(cin, formaPagamento);

    cout << "Tarefa: ";
    getline(cin, tarefa);

    if(verificaPorCpf(lista_cliente,cpf)){ ///Chama a função do tad_lista para verificar se já está cadastrado
        cout << "Cliente já cadastrado"<< endl;
        return false;
    }

    Cliente novo_cliente(nome, endereco, cpf, telefone, formaPagamento, tarefa);
    insere_fim(lista_cliente, novo_cliente);
    cout << "\nCliente cadastrado com Sucesso!" << endl;
    return true;
}

bool Sistema::cadastrar(int escolha_funcao) { ///Cadastrar para trabalhador
    string nome, endereco, profissao, experiencia, tipo, materiais;
    long long int cpf, telefone;
    float custo;

    cout << "Nome: ";
    cin.ignore(); // Ignora o caractere de nova linha remanescente no buffer
    getline(cin, nome);

    cout << "Endereço: ";
    getline(cin, endereco);

    cout << "CPF: ";
    cin >> cpf;

    cout << "Telefone: ";
    cin >> telefone;
    cin.ignore();

    cout << "Experiência: ";
    getline(cin, experiencia);

    cout << "Tipo de serviço: ";
    getline(cin, tipo);

    cout << "Materiais e ferramentas: ";
    getline(cin, materiais);

    cout << "Custo por hora: ";
    cin >> custo;

    profissao = profissaoPorInt(escolha_funcao);



    if(verificaTrabalhadorCadastrado(lista_trabalhador,cpf, profissao)){ ///Chama a função do tad_lista para verificar se já está cadastrado
        cout << "Trabalhador já cadastrado para esta função"<< endl;
        return false;
    }

    Trabalhador *novo_trab;

    if (escolha_funcao == 1){
        novo_trab = new Pedreiro(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if (escolha_funcao == 2){
        novo_trab = new Jardineiro(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if (escolha_funcao == 3){
        novo_trab = new Encanador(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if (escolha_funcao == 4){
        novo_trab = new Eletricista(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if(escolha_funcao == 5){
        novo_trab = new Pintor(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if(escolha_funcao == 6){
         novo_trab = new LimpadorDePiscina(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if(escolha_funcao == 7){
         novo_trab = new Carpinteiro(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else if(escolha_funcao == 8){
         novo_trab = new Faxineiro(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }else{
        novo_trab = new Dedetizador(nome, endereco, cpf, telefone, profissao, experiencia, tipo, materiais, custo);
    }

    insere_fim(lista_trabalhador, *novo_trab);

    insere_fim(lista_trabalhador_disponivel, *novo_trab); /// Insere na Lista de Disponíveis

    cout << "\nTrabalhador cadastrado com Sucesso!" << endl;
    return true;
}

void Sistema::removerCliente(long long int cpf) {
    int i = encontrarPosicaoPorCPF(lista_cliente, cpf);
    if(i==-1){
        cout<<"Cliente inexistente!"<<endl;
    }else{
        remove_posicao(lista_cliente, i);
        cout<<"Removido com sucesso!"<<endl;
    }
}

void Sistema::removerTrabalhador(long long int cpf) {
    int posicaoTrabalhador = encontrarPosicaoPorCPF(lista_trabalhador, cpf);
    int posicaoTrabalhadorDisponivel = encontrarPosicaoPorCPF(lista_trabalhador_disponivel, cpf);
    int posicaoContrato = encontrarPosicaoContratoCpf(lista_contratos, cpf);

    if(posicaoTrabalhador==-1){
        cout<<"Trabalhador inexistente!"<<endl;
    }else{
        remove_posicao(lista_trabalhador, posicaoTrabalhador);
        remove_posicao(lista_trabalhador_disponivel, posicaoTrabalhadorDisponivel);
        remove_posicao(lista_contratos, posicaoContrato);
        cout<<"Removido com sucesso!"<<endl;
    }
}

void Sistema::pesquisaCliente(long long int cpf) {
  imprimePorCpf(lista_cliente, cpf);
}

void Sistema::pesquisaTrabalhador(long long int cpf) {
  imprimePorCpf(lista_trabalhador, cpf);
}

void Sistema::imprimeListaClientes() {
    cout << "Lista de Clientes" << endl << endl;

    TElemento<Cliente> *atual = lista_cliente.inicio;
    while (atual != NULL) {
        atual->dado.imprime();
        cout << endl;
        atual = atual->proximo;
    }
}

void Sistema::imprimeListaTrabalhadores() {
    cout << "Lista de Trabalhadores" << endl << endl;
    TElemento<Trabalhador> *atual = lista_trabalhador.inicio;
    while (atual != NULL) {
        atual->dado.imprime();
        cout << endl;
        atual = atual->proximo;
    }
}

void Sistema::imprimeListaTrabalhadoresDisponiveis(string data) {
    TElemento<Trabalhador> *atual = lista_trabalhador_disponivel.inicio;

    if (lista_trabalhador_disponivel.inicio == NULL){
        cout << "Não há trabalhadores disponíveis para " << data << endl;
        return;
    }

    cout << "Lista de Trabalhadores Disponíveis para " << data << endl << endl;
    while (atual != NULL) {

    if (verificaDisponibilidade(atual->dado, data)){
        atual->dado.imprime();
        cout << endl;
    }
        atual = atual->proximo;
    }
}

//void Sistema::editarCliente(){
//}


TListaE<Contrato> &Sistema::get_lista_contratos() { return lista_contratos; }

TListaE<Trabalhador> &Sistema::get_lista_trabalhador() { return lista_trabalhador; }

TListaE<Cliente> &Sistema::get_lista_cliente() { return lista_cliente; }

TListaE<Trabalhador> &Sistema::get_lista_trabalhador_disponivel() { return lista_trabalhador_disponivel; }


#endif
