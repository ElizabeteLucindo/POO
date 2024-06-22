#ifndef TRABALHADOR_ESPECIFICO_H
#define TRABALHADOR_ESPECIFICO_H

#include "Trabalhador.h"

class Pedreiro : public Trabalhador{
private:
    string tipoServico;
    string materiaisFerramentas;
    float custoServicoHora;

public:
    Pedreiro();
    Pedreiro(const string n, const string e, long long int c, int t, string p, string ex ,string tipo, string materiais, float custo);
    void setTipoServico(string tipo);
    void setMateriaisFerramentas(string materiais);
    void setCustoServicoHora(float custo);
    string getTipoServico() const;
    string getMateriaisFerramentas() const;
    float getCustoServicoHora() const;
    void imprime();
};
Pedreiro::Pedreiro() {}
Pedreiro::Pedreiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo)
: Trabalhador(n, e, c, t, p, ex), tipoServico(tipo), materiaisFerramentas(materiais), custoServicoHora(custo) {}

void Pedreiro::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Pedreiro::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Pedreiro::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Pedreiro::getTipoServico() const{
  return tipoServico;
}
string Pedreiro::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Pedreiro::getCustoServicoHora() const{
  return custoServicoHora;
}
void Pedreiro::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Jardineiro: public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Jardineiro();
Jardineiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Jardineiro::Jardineiro(){}
Jardineiro::Jardineiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo)
: Trabalhador(n, e, c, t, p, ex), tipoServico(tipo), materiaisFerramentas(materiais), custoServicoHora(custo) {}

void Jardineiro::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Jardineiro::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Jardineiro::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Jardineiro::getTipoServico() const{
  return tipoServico;
}
string Jardineiro::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Jardineiro::getCustoServicoHora() const{
  return custoServicoHora;
}
void Jardineiro::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Encanador:public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Encanador();
Encanador(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Encanador::Encanador(){}
Encanador::Encanador(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
Trabalhador(n, e, c, t, p, ex), tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}
void Encanador::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Encanador::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Encanador::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Encanador::getTipoServico() const{
  return tipoServico;
}
string Encanador::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Encanador::getCustoServicoHora() const{
  return custoServicoHora;
}
void Encanador::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Eletricista: public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Eletricista();
Eletricista(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Eletricista::Eletricista(){}
Eletricista::Eletricista(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
Trabalhador(n, e, c, t, p, ex), tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}
void Eletricista::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Eletricista::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Eletricista::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Eletricista::getTipoServico() const{
  return tipoServico;
}
string Eletricista::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Eletricista::getCustoServicoHora() const{
  return custoServicoHora;
}
void Eletricista::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
  }

class Pintor: public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Pintor();
Pintor(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Pintor::Pintor(){}
Pintor::Pintor(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
Trabalhador(n, e, c, t, p, ex), tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}
void Pintor::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Pintor::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Pintor::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Pintor::getTipoServico() const{
  return tipoServico;
}
string Pintor::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Pintor::getCustoServicoHora() const{
  return custoServicoHora;
}
void Pintor::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class LimpadorDePiscina : public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
LimpadorDePiscina();
LimpadorDePiscina(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
LimpadorDePiscina::LimpadorDePiscina(){}
LimpadorDePiscina::LimpadorDePiscina(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo)
: Trabalhador(n, e, c, t, p, ex), tipoServico(tipo), materiaisFerramentas(materiais), custoServicoHora(custo) {}

void LimpadorDePiscina::setTipoServico(string tipo){
  tipoServico = tipo;
}
void LimpadorDePiscina::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void LimpadorDePiscina::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string LimpadorDePiscina::getTipoServico() const{
  return tipoServico;
}
string LimpadorDePiscina::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float LimpadorDePiscina::getCustoServicoHora() const{
  return custoServicoHora;
}
void LimpadorDePiscina::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Carpinteiro: public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Carpinteiro();
Carpinteiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Carpinteiro::Carpinteiro(){}
Carpinteiro::Carpinteiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
Trabalhador(n, e, c, t, p, ex), tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}

void Carpinteiro::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Carpinteiro::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Carpinteiro::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Carpinteiro::getTipoServico() const{
  return tipoServico;
}
string Carpinteiro::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Carpinteiro::getCustoServicoHora() const{
  return custoServicoHora;
}
void Carpinteiro::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Faxineiro:public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Faxineiro();
Faxineiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Faxineiro::Faxineiro(){}
Faxineiro::Faxineiro(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}
void Faxineiro::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Faxineiro::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Faxineiro::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Faxineiro::getTipoServico() const{
  return tipoServico;
}
string Faxineiro::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Faxineiro::getCustoServicoHora() const{
  return custoServicoHora;
}
void Faxineiro::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
}

class Dedetizador:public Trabalhador{
private:
string tipoServico, materiaisFerramentas;
float custoServicoHora;
public:
Dedetizador();
Dedetizador(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo);
void setTipoServico(string tipo);
void setMateriaisFerramentas(string materiais);
void setCustoServicoHora(float custo);
string getTipoServico() const;
string getMateriaisFerramentas() const;
float getCustoServicoHora() const;
void imprime();
};
Dedetizador::Dedetizador(){}
Dedetizador::Dedetizador(const string n, const string e, long long int c, int t, string p, string ex, string tipo, string materiais, float custo):
Trabalhador(n, e, c, t, p, ex), tipoServico(tipo),materiaisFerramentas(materiais),custoServicoHora(custo){}
void Dedetizador::setTipoServico(string tipo){
  tipoServico = tipo;
}
void Dedetizador::setMateriaisFerramentas(string materiais){
  materiaisFerramentas = materiais;
}
void Dedetizador::setCustoServicoHora(float custo){
  custoServicoHora = custo;
}
string Dedetizador::getTipoServico() const{
  return tipoServico;
}
string Dedetizador::getMateriaisFerramentas() const{
  return materiaisFerramentas;
}
float Dedetizador::getCustoServicoHora() const{
  return custoServicoHora;
}
void Dedetizador::imprime(){
  Trabalhador::imprime();
  cout << "Tipo de serviço: " << tipoServico << endl;
  cout << "Materiais e ferramentas: " << materiaisFerramentas<<endl;
  cout << "Custo por hora: " << custoServicoHora << endl;
  }

#endif
