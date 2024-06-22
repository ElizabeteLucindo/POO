#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pessoa.h"

class Cliente : public Pessoa{
private:
  string tarefa, formaPagamento;

public:
  Cliente();
  Cliente(const string n, const string e, long long int c, long long int t, string fp, string ta);
  void setFormaPagamento(string fp);
  void setTarefa(const string ta);
  string getFormaPagamento() const;
  string getTarefa() const;
  void imprime();
  bool operator==(const Cliente& outro) const; // Sobrecarga do operador ==
};

Cliente::Cliente(){}
Cliente::Cliente(const string n, const string e, long long int c,long long int t, string fp, string ta)
: Pessoa(n, e, c, t), tarefa(ta), formaPagamento(fp){}

void Cliente::setFormaPagamento(string fp){
  formaPagamento = fp;
}

void Cliente::setTarefa(const string ta){
  tarefa = ta;
}

string Cliente::getFormaPagamento() const{
  return formaPagamento;
}

string Cliente::getTarefa() const{
  return tarefa;
}

void Cliente::imprime(){
  Pessoa::imprime();
  cout << "Tarefa: " << tarefa << endl;
  cout << "Forma de pagamento: " << formaPagamento << endl;
}

bool Cliente::operator==(const Cliente& outro) const {
  return nome == outro.nome && endereco == outro.endereco && cpf == outro.cpf && telefone == outro.telefone;
}

#endif