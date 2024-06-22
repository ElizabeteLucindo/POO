#ifndef CONTRATO_H
#define CONTRATO_H
#define MAX 20

#include "Sistema.h"

class Contrato {
private:
  Trabalhador trabalhador;
  Cliente cliente;
  string data;

public:
  Contrato();
  Contrato(Trabalhador trab, Cliente cl, string dat);
  string getData();
  Trabalhador getTrabalhador(); 
  Cliente getCliente();
};

Contrato::Contrato(){}

Contrato::Contrato(Trabalhador trab, Cliente cl, string dat)
: trabalhador(trab), cliente(cl), data(dat) {}

string Contrato::getData(){
  return data;
}

Trabalhador Contrato::getTrabalhador(){
  return trabalhador;
}

Cliente Contrato::getCliente(){
  return cliente;
}

#endif