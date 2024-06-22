/*Trabalho M1 - Marido de Aluguel
  Professor:Thiago Felski Pereira
  Alunas:Elizabete Lucindo Silva,Fabiane Santos Soares e Marilia Hentz
*/

#include <iostream>
using namespace std;
#define MAX 20
#include "Sistema.h"


int main() {
  Sistema sistema;
  
  Cliente cliente1("Ana Maria da Silva", "Rua Uruguai,83", 123456, 479473286, "cartão", "mecânico");
  
   sistema.cadastrarCliente(cliente1);
  
  Cliente cliente2("Lola Maria", "Rua João Gaya,82", 8765432, 5597189986, "dinheiro", "pedreiro");
  
  sistema.cadastrarCliente(cliente2);
 
  Trabalhador trabalhador1("Tadeu dos Santos", "Rua Beija-Flor", 476789642, 476234580, "mecânico", "10 anos");

  Pedreiro pedreiro1("João Carlos Meireles", "Rua dos Arcos", 66666666, 477777, "pedreiro", "20 anos", "construção", "cimento e ferramentas", 40);
  cout<<endl<<endl;
  
  sistema.cadastrarTrabalhador(trabalhador1);
  sistema.cadastrarTrabalhador(pedreiro1);
  
  sistema.contratarServico(pedreiro1, cliente2 ,"20/04/2024");
  cout<<endl<<endl;
  
  sistema.contratarServico(pedreiro1, cliente1 ,"20/04/2024");
  cout<<endl<<endl;

  

  sistema.imprimirContratos(cliente1);
  sistema.imprimirContratos(cliente2);
  cout<<endl;
  sistema.imprimeListaClientes();
  sistema.imprimeListaTrabalhadores();
  
}