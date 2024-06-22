/*Trabalho M2 - Marido de Aluguel
  Professor:Thiago Felski Pereira
  Alunas:Elizabete Lucindo Silva,Fabiane Santos Soares e Marilia Hentz
*/

/// Usar heranças múltiplas, sobrecarga e sobrescrita
/// Salvar os disponiveis (fica removendo cada vez q inicia o programa)
/// Salvar contratos também fica estranho
/// Acentos da letra desconfigurado (codeblocks)


#include <iostream>
using namespace std;
#define TAM_LISTA 50
#include "TAD_Lista.h"
#include "Sistema.h"
#include <fstream>
#include"arq.h"
#include <locale.h>



// Limpar a tela do console
/*void clear() {
    (void)system("clear");
}*/

void clear() {
    system("cls");
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    Sistema sistema;

    sistema.inicializa_listas();

    leitura_arq(sistema.get_lista_trabalhador(), sistema.get_lista_cliente(), sistema.get_lista_contratos(), sistema.get_lista_trabalhador_disponivel());

    int escolha;
    do {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar" << endl;
        cout << "2. Remover" << endl;
        cout << "3. Contratar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Pesquisar" << endl;
        cout << "6. Editar" << endl;
        cout << "7. Sair" << endl;

        cout << "Escolha uma opção: ";
        cin >> escolha;

        clear();

        switch (escolha) {
            case 1:
                int escolha_cadastrar;
                cout << "CADASTRAR" << endl << endl;
                cout << "1. Cliente" << endl;
                cout << "2. Trabalhadores" << endl;
                cin >> escolha_cadastrar;

                if (escolha_cadastrar == 1){ //////////////////////////////
                    clear();
                    cout << "Cadastro de Cliente" << endl;
                    sistema.cadastrar();

                }else if(escolha_cadastrar == 2){
                    clear();
                    int escolha_funcao;
                    cout << "Cadastro de Trabalhador." << endl;
                    cout << "\n1. Pedreiro" << endl;
                    cout << "2. Jardineiro" << endl;
                    cout << "3. Encanador" << endl;
                    cout << "4. Eletricista" << endl;
                    cout << "5. Pintor" << endl;
                    cout << "6. Limpador de Piscina" << endl;
                    cout << "7. Carpinteiro" << endl;
                    cout << "8. Faxineiro" << endl;
                    cout << "9. Dedetizador" << endl;
                    cin >> escolha_funcao;

                    clear();
                    if (escolha_funcao > 9 || escolha_funcao < 1){
                        cout << "Opção inválida." << endl;
                        clear();
                        break;
                    }
                    sistema.cadastrar(escolha_funcao);

                } else{
                    clear();
                    cout << "Valor Incorreto" << endl;
                    clear();
                }
                break;

            case 2: ///Remover
                int escolha_remover;
                cout << "REMOVER" << endl << endl;
                cout << "1. Cliente" << endl;
                cout << "2. Trabalhadores" << endl;
                cin >> escolha_remover;

                if (escolha_remover == 1){
                    clear();
                    long long int cpf;
                    cout << "Digite o CPF da pessoa"<<endl;
                    cin >> cpf;
                    sistema.removerCliente(cpf);

                }else if (escolha_remover == 2){
                    clear();
                    long long int cpf;
                    cout << "Digite o CPF da pessoa"<<endl;
                    cin >> cpf;
                    sistema.removerTrabalhador(cpf);

                }else{
                    clear();
                    cout << "Valor Incorreto" << endl;
                    clear();
                }
                break;

            case 3: {////Contratar Serviço/////////////////////ALTERAR
                string nome_cliente, nome_trabalhador, data;
                cout << "CONTRATAR SERVIÇO" << endl << endl;
                cout << "Nome do cliente: ";
                cin.ignore();  // Limpar o buffer de entrada
                getline(cin, nome_cliente);

                cout << "\nNome do trabalhador: ";
                getline(cin,nome_trabalhador);

                cout << "\nData (dd/mm/aa): ";
                cin >> data;

                /*if (!verificaDataValida(data)){
                    cout << "Data inválida ou anterior a data atual"<<endl;
                    break;
                }*/

                sistema.contratarServico(nome_cliente, nome_trabalhador ,data);

                break;}

            case 4:///Listar
                cout << "LISTAR" << endl << endl;
                int escolha_lista;
                cout << "1. Clientes" << endl;
                cout << "2. Todos Trabalhadores" << endl;
                cout << "3. Trabalhadores Disponíveis" << endl;
                cout << "4. Contrato" << endl;
                cin >> escolha_lista;

                if (escolha_lista == 1){
                    clear();
                    sistema.imprimeListaClientes();

                }else if (escolha_lista == 2){
                    clear();
                    sistema.imprimeListaTrabalhadores();

                }else if (escolha_lista == 3){
                    clear();
                    string data;
                    cout << "Digite a data (dd/mm/aa)" << endl;
                    cin >> data;

                    /*if (!verificaDataValida(data)){
                    cout << "Data inválida ou anterior a data atual"<<endl;
                    break;
                    }*/

                    sistema.imprimeListaTrabalhadoresDisponiveis(data);


                }else if ( escolha_lista == 4){
                    clear();
                    long long int cpf_cliente;

                    cout << "CPF do Cliente: ";
                    cin >> cpf_cliente;

                    if(!verificaPorCpf(sistema.get_lista_cliente(), cpf_cliente)){
                        cout<<"\nCliente Inexistente"<<endl;
                        break;
                    }

                    Cliente cliente = encontraPorCpf(sistema.get_lista_cliente(), cpf_cliente);

                    sistema.imprimirContratos(cliente);

                }else{
                    clear();
                    cout << "Valor Incorreto" << endl;
                }
                break;

            case 5: /// Pesquisar
                int escolha_pesquisa;
                cout << "PESQUISAR" << endl << endl;
                cout << "1. Cliente" << endl;
                cout << "2. Trabalhador" << endl;
                cin >> escolha_pesquisa;

                clear();
                long long int cpf;
                cout << "CPF: ";
                cin >> cpf;

                if (escolha_pesquisa == 1){
                    clear();
                    sistema.pesquisaCliente(cpf);

                }else if(escolha_pesquisa == 2){
                    clear();
                    sistema.pesquisaTrabalhador(cpf);

                }else{
                    clear();
                    cout << "Valor Incorreto" << endl;
                }
                break;

            case 6: /// Editar
                int escolha_editar;


                cout << "EDIÇÃO" << endl<<endl;
                cout << "1. Cliente" << endl;;
                cout << "2. Trabalhador" << endl;
                cin >> escolha_editar;

                if (escolha_editar == 1){
                    clear();
                    long long int cpf_busca;
                    cout << "Editar Cliente" <<endl;/////////////////////
                    cout << "Digite o CPF: ";
                    cin >> cpf_busca;
                    //sistema.editarCliente(cpf_busca);


                }else if (escolha_editar == 2){
                    clear();
                    cout << "Editar Trabalhador" <<endl;/////////////////////

                }else{
                    clear();
                    cout << "Valor Incorreto" << endl;
                }
                break;
            case 7:
                cout << "FIM!" << endl;
                escrita_arq (sistema.get_lista_trabalhador(), sistema.get_lista_cliente(), sistema.get_lista_contratos(), sistema.get_lista_trabalhador_disponivel());
                break;


            default:
                cout << "Opção inválida. Tente novamente." << endl;
                clear();
                break;
        }
    } while (escolha != 7);

}

