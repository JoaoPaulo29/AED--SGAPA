#include "pilhacontentor.h"
#define MAX_PILHA_LISTA 2

typedef struct {
	PILHA_CONT p[MAX_PILHA_LISTA];
	int qtd;
} listaDpilha;

listaDpilha * criaListaDpilha () {
	listaDpilha *lista = (listaDpilha *) malloc (sizeof (listaDpilha));
	int i = 0;
	for (; i < MAX_PILHA_LISTA; i++)
		lista->p[i] = *cria_pilha_cont ();
	return lista;
}

int isVaziaListaPilha (listaDpilha lista) {
	int i = 0;
	for (; i < MAX_PILHA_LISTA; i++)
		if (!isVaziaPilhaCont (lista.p[i])) return 0;
	return 1;
}

int isCheiaListaPilha (listaDpilha lista) {
	int i = 0;
	for (; i < MAX_PILHA_LISTA; i++)
		if (!isCheiaPilhaCont (lista.p[i])) return 0;
	return 1;
}

int insereNlistaDpilha (listaDpilha *lista, CONTENTOR c) {
	if (!isCheiaListaPilha (*lista)) {
		int i = 0;
		for (; i < MAX_PILHA_LISTA; i++)
			if (empilhar (&lista->p[i], c)) return 1;
	}
	return 0;	
}

void listaListaDpilha (listaDpilha lista) {
	if (isVaziaListaPilha (lista)) puts ("SECAO VAZIA!");
	else {
		int i = 0;
		puts ("SECCAO");
		puts ("_______________________________________________________");
		for (; i < MAX_PILHA_LISTA; i++)
			puts ("------------------------------------------------------"),
			lista_pilha (lista.p[i]);
	}
}
