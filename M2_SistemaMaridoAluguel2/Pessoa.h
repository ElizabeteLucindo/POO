#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;

class Pessoa{
protected:
  string nome, endereco;
  long long int cpf;
  long long int telefone;

public:
  Pessoa();
  Pessoa(const string n, const string e, long long int c, long long int t);
  void setNome(const string n);

  void setEndereco(const string e);
  void setCpf(long long int c);
  void setTelefone(int t);
  string getNome() const; // const para dizer que não muda
  string getEndereco() const;
  int getCpf() const;
  int getTelefone() const;
  void imprime();
};

Pessoa::Pessoa(){}
Pessoa::Pessoa(const string n, const string e, long long int c, long long int t)
: nome(n), endereco(e), cpf(c), telefone(t){}
void Pessoa::setNome(const string n){
  nome = n;
}

void Pessoa::setEndereco(const string e){
  endereco = e;
}

void Pessoa::setCpf(long long int c){
  cpf = c;
}

void Pessoa::setTelefone(int t){
  telefone = t;
}

string Pessoa::getNome() const{
  return nome;
}

string Pessoa::getEndereco() const{
  return endereco;
}

int Pessoa::getCpf() const{
  return cpf;
}

int Pessoa::getTelefone() const{
  return telefone;
}

void Pessoa::imprime(){
  cout << "Nome: " << nome << endl;
  cout << "Endereço: " << endereco << endl;
  cout << "CPF: " << cpf << endl;
  cout << "Telefone: " << telefone << endl;
}

#endif
