#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <ctime>
// Inicializa_lista, insere_(fim,inicio,posicao), remover, qtd

template <typename TIPO>
struct TElemento {
    TIPO dado;
    TElemento<TIPO> *proximo;
};

template <typename TIPO>
struct TListaE {
    TElemento<TIPO> *inicio;
};

template <typename TIPO>
bool inicializa_lista(TListaE<TIPO> &lista) {
    lista.inicio = NULL;
    return true;
}

template <typename TIPO> // Função para alocação dinâmica
TElemento<TIPO> *novoElementoLista(TIPO dado) { // retorna um ponteiro
    TElemento<TIPO> *novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

template <typename TIPO>
int qtd(TListaE<TIPO> lista) {
    TElemento<TIPO> *nav = lista.inicio;
    int i;
    for (i = 0; nav != NULL; i++) {
    nav = nav->proximo;
    }
    return i;
}


template <typename TIPO>
bool insere_inicio(TListaE<TIPO> &lista, TIPO dado) {
    TElemento<TIPO> *novo = novoElementoLista(dado);
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    return true;
}


template <typename TIPO>
bool insere_fim(TListaE<TIPO> &lista, TIPO dado) {
    TElemento<TIPO> *nav = lista.inicio;
    TElemento<TIPO> *novo = novoElementoLista(dado);
    if (lista.inicio != NULL) { // se a lista nao for vazia
        while (nav->proximo != NULL) { // percorre a lista até chegar no ultimo elemento
            nav = nav->proximo;
    }
    novo->proximo = NULL;
    nav->proximo = novo;
    return true;
    } else { // se a lista for vazia, vai inserir no inicio
        novo->proximo = NULL;
        lista.inicio = novo;
        return true;
    }
}


template <typename TIPO>
bool insere_posicao(TListaE<TIPO> &lista, TIPO dado, int posicao) {
    if (posicao == 0) { // Se for inserir no inicio
        TElemento<TIPO> *novo = novoElementoLista(dado);
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        return true;
    } else { // inserir em outra posicao que não seja 0
        TElemento<TIPO> *nav = lista.inicio;
        int i=0;
        while (i < posicao - 1 && nav != NULL) {
            nav = nav->proximo;
            i++;
        }
        if (nav != NULL) {
            TElemento<TIPO> *novo = novoElementoLista(dado);
            novo->proximo = nav->proximo;
            nav->proximo = novo;
            return true;
        } else {
            return false;
        }
    }
}

template <typename TIPO>
bool remove_inicio(TListaE<TIPO> &lista) {
    if (lista.inicio == NULL)
        return false;
    else {
        lista.inicio = lista.inicio->proximo;
        return true;
    }
}

template <typename TIPO, int MAX>
bool remove_fim(TListaE<TIPO> &lista) {
    if (lista.inicio == NULL) // não se remove lista vazia
        return false;
    else {
        TElemento<TIPO> *nav = lista.inicio;
        if (nav->proximo == NULL) { // se tiver apenas um elemento
            lista.inicio = NULL;
            delete nav;
            return true;
        }
        else {
            TElemento<TIPO> *p = lista.inicio->proximo;
            while (p->proximo != NULL) {
                nav = nav->proximo;
                p = p->proximo;
            }
            nav->proximo = NULL;
            delete p;
            return true;
        }
    }
}



template <typename TIPO>
bool remove_posicao(TListaE<TIPO> &lista, int posicao) {
  if (lista.inicio == NULL || posicao < 0) {
    return false;
  } else {
    if (posicao == 0) { // se for remover o primeiro elemento
      TElemento<TIPO> *ap = lista.inicio;
      lista.inicio = ap->proximo; // o segundo elemento vira o primeiro
      if (ap != NULL) {
        delete ap;
      }
      return true;
    } else { // se for remover de outra posicao que nao seja 0
      TElemento<TIPO> *nav = lista.inicio;
      if (lista.inicio->proximo == NULL) { // Posicao invalida
        return false;
      }
      int i=0;
      TElemento<TIPO> *p = lista.inicio->proximo;
      while (i < posicao - 1 && nav->proximo != NULL) {
        nav = nav->proximo;
        p = p->proximo;
        i++;
      }
      if (i == posicao - 1) {
        if (p != NULL) {
          nav->proximo = p->proximo;
          delete p;
        }
      }
      return true;
    }
  }
}


template <typename TIPO>
bool bubblesort(TListaE<TIPO> &lista) {
  int TAM = qtd(lista); // Número de elementos da lista

  if (TAM <= 1) // não tem nada para sortear
    return false;

  int cond;
  TElemento<TIPO> *nav = lista.inicio;
  cond = 1;
  for (int i = TAM - 1; (i >= 1) && (cond == 1);i--) {
    cond = 0;
    nav = lista.inicio; // volta para o inicio a cada loop para percorrer a lista

    for (int j = 0; j < i; j++) {
      if (nav->dado > nav->proximo->dado) { // se o dado da frente for menor que
                                            // o atual ira fazer a troca
        TIPO aux = nav->dado;
        nav->dado = nav->proximo->dado; // o dado atual recebe o dado da frente
        nav->proximo->dado = aux;       // o dado da frente recebe o dado atual
        cond = 1;                       // a lista não esta ordenada
      }
      nav = nav->proximo;
    }
  }
}


template <typename TIPO>
TElemento<TIPO> *elemento_lista(TListaE<TIPO> lista, int posicao) {
  int i = 0;
  TElemento<TIPO> *nav = lista.inicio;
  while (i < posicao && nav != NULL) {
    nav = nav->proximo;
    i++;
  }
  return nav;
}


template <typename TIPO>
int encontrarPosicao(TListaE<TIPO> &lista, TIPO elemento) {
    int posicao = 0;
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o elemento ou o fim da lista
    while (nav != NULL) {
        // Se o elemento atual for igual ao elemento procurado, retorna a posição
        if (nav->dado == elemento) {
            return posicao;
        }
        // Avança para o próximo nó e incrementa a posição
        nav = nav->proximo;
        posicao++;
    }
    // Se o elemento não for encontrado, retorna -1
    return -1;
}

template <typename TIPO>
int encontrarPosicaoPorCPF(TListaE<TIPO> lista, long long int cpf) {
    int posicao = 0;
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o cliente com o CPF correspondente ou o fim da lista
    while (nav != NULL) {
        // Verifica se o dado do elemento atual é um cliente e se o CPF corresponde
        if (nav->dado.getCpf() == cpf) {
            return posicao;
        }
        // Avança para o próximo nó e incrementa a posição
        nav = nav->proximo;
        posicao++;
    }
    // Se o cliente com o CPF especificado não for encontrado, retorna -1
    return -1;
}

template<typename TIPO>
void imprimePorCpf(TListaE<TIPO> &lista, long long int cpf) {
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o elemento com o CPF correspondente ou o fim da lista
    while (nav != NULL) {
        // Verifica se o dado do elemento atual tem o CPF correspondente
        if (nav->dado.getCpf() == cpf) {
            nav->dado.imprime();
        }
        // Avança para o próximo nó
        nav = nav->proximo;
    }
}

template<typename TIPO>
bool verificaPorCpf(TListaE<TIPO> &lista, long long int cpf) {
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o elemento com o CPF correspondente ou o fim da lista
    while (nav != NULL) {
        // Verifica se o dado do elemento atual tem o CPF correspondente
        if (nav->dado.getCpf() == cpf) {
            return true; /// já existe
        }
        // Avança para o próximo nó
        nav = nav->proximo;
    }return false; ///nao existe
}

template<typename TIPO>
TIPO encontraPorCpf(TListaE<TIPO> &lista, long long int cpf) { ///Retorna o cliente/trabalhador
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o elemento com o CPF correspondente ou o fim da lista
    while (nav != NULL) {
        // Verifica se o dado do elemento atual tem o CPF correspondente
        if (nav->dado.getCpf() == cpf) {
            return nav->dado; /// já existe
        }
        // Avança para o próximo nó
        nav = nav->proximo;
    }return TIPO(); ///nao existe
}

template<typename TIPO>
TIPO encontraPorNome(TListaE<TIPO> &lista, string& nome) {
    TElemento<TIPO>* nav = lista.inicio;

    while (nav != NULL) {
        if (nav->dado.getNome() == nome) {
            return nav->dado;
        }
        nav = nav->proximo;
    }

    return TIPO();
}


template<typename TIPO>
bool verificaTrabalhadorCadastrado(TListaE<TIPO> &lista, long long int cpf, string profissao){
    TElemento<TIPO> *nav = lista.inicio;

    while (nav != NULL) {
        // Verifica se o dado do elemento atual tem o CPF e Profissao correspondente
        if ((nav->dado.getCpf() == cpf) && (nav->dado.getProfissao() == profissao)) {
            return true; /// já existe
        }
        // Avança para o próximo nó
        nav = nav->proximo;
    }return false; ///nao existe
}


template <typename TIPO>
int encontrarPosicaoContratoCpf(TListaE<TIPO> lista, long long int cpf) {
    int posicao = 0;
    TElemento<TIPO> *nav = lista.inicio;

    // Percorre a lista até encontrar o cliente com o CPF correspondente ou o fim da lista
    while (nav != NULL) {
        // Verifica se o dado do elemento atual é um cliente e se o CPF corresponde
        if (nav->dado.getTrabalhador().getCpf() == cpf) {
            return posicao;
        }
        // Avança para o próximo nó e incrementa a posição
        nav = nav->proximo;
        posicao++;
    }
    // Se o cliente com o CPF especificado não for encontrado, retorna -1
    return -1;
}



///Funções Auxiliares

///int profissao para string
string profissaoPorInt(int escolha_funcao) {
    switch(escolha_funcao) {
        case 1: return "Pedreiro";
        case 2: return "Jardineiro";
        case 3: return "Encanador";
        case 4: return "Eletricista";
        case 5: return "Pintor";
        case 6: return "Limpador de Piscina";
        case 7: return "Carpinteiro";
        case 8: return "Faxineiro";
        case 9: return "Dedetizador";
        default: return "Profissão inválida";
    }
}

// Assuming TListaE is a template class
/*template<typename TIPO>
void atualizaCampo(TListaE<TIPO> &lista, long long int cpf_buscado, int campo, TIPO novo_valor) {
    TElemento<TIPO> *atual = lista.inicio;

    while (atual != NULL) {
        if (atual->dado.getCpf() == cpf_buscado) {
            switch (campo) {
                case 1:
                    atual->dado.setNome(novo_valor);
                    break;
                case 2:
                    atual->dado.setEndereco(novo_valor);
                    break;
                case 3:
                    atual->dado.setCpf(novo_valor);
                    break;
                case 4:
                    atual->dado.setTelefone(novo_valor);
                    break;
                case 5:
                    atual->dado.setTarefa(novo_valor);
                    break;
                case 6:
                    atual->dado.setFormaPagamento(novo_valor);
                    break;
                default:
                    cout << "Campo inválido" << endl;
                    return;
            }
            return; // Exit loop once the element is updated
        }
        atual = atual->proximo;
    }
    cout << "CPF não encontrado" << endl;
}*/


///Verificar data
/*bool verificaDataValida(string data){

    /// Verificar se a string possui o tamanho mínimo esperado
    if (data.size() != 10) // dd/mm/aaaa
        return false;

     /// Obter a data atual do sistema
    time_t tempoAtual = time(nullptr);
    tm* dataAtual = localtime(&tempoAtual);

    /// Extrair dia, mês e ano da data atual
    int diaAtual = dataAtual->tm_mday;
    int mesAtual = dataAtual->tm_mon + 1; // Adicionar 1 porque tm_mon é base zero
    int anoAtual = dataAtual->tm_year + 1900; // Adicionar 1900 porque tm_year é o número de anos desde 1900

    /// Converter os componentes da data para inteiros
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));

    /// Verificar se a data fornecida é posterior à data atual
    if (ano < anoAtual || (ano == anoAtual && mes < mesAtual) || (ano == anoAtual && mes == mesAtual && dia < diaAtual))
        return false;

    /// Verificar o dia, mês e ano válidos
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0)
        return false;
     /// Verificar meses com menos de 31 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;
     /// Verificar fevereiro
    if (mes == 2) {
        if (dia > 29)
            return false;
    }
    return true;
}*/


#endif

