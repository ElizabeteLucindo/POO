#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include "Pessoa.h"

class Trabalhador : public Pessoa {
private:
    string profissao, experiencia;
    string datasAgendadas[TAM_LISTA];
    int numServicos = 0;


public:
    Trabalhador();
    Trabalhador(const string n, const string e, long long int c, int t, string p, string ex);
    void setProfissao(const string p);
    void setExperiencia(const string ex);
    string getProfissao() const;
    string getExperiencia() const;
    void adicionarServico(const string& data);
    bool verificaDisponibilidade(const string& data);
    void imprime();
    bool operator==(const Trabalhador& outro) const;
};

Trabalhador::Trabalhador() {}
Trabalhador::Trabalhador(const string n, const string e, long long int c, int t, string p, string ex)
: Pessoa(n, e, c, t), profissao(p), experiencia(ex){}

void Trabalhador::setProfissao(const string p){
  profissao = p;
}

void Trabalhador::setExperiencia(const string ex){
  experiencia = ex;
}

string Trabalhador::getProfissao() const{
  return profissao;
}

string Trabalhador::getExperiencia() const{
  return experiencia;
}

void Trabalhador::adicionarServico(const string& data){
  if (numServicos < TAM_LISTA) {
    datasAgendadas[numServicos] = data;
    numServicos++;
  } else {
    cout << "Erro: Não foi possível adicionar a data agendada. Limite de serviços alcançado." << endl;
  }
}

bool Trabalhador::verificaDisponibilidade(const string& data){

  for (int i = 0; i < numServicos; i++){
    if(datasAgendadas[i] == data){
      return false;
    }
  }return true;
}



void Trabalhador::imprime(){
  Pessoa::imprime();
  cout << "Profissão: " << profissao << endl;
  cout << "Experiência: " << experiencia << endl;
}

bool Trabalhador::operator==(const Trabalhador& outro) const {
    return nome == outro.nome && endereco == outro.endereco && cpf == outro.cpf && telefone == outro.telefone;
}
#endif
