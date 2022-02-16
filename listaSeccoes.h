#include "listaDpilha.h"
#define MAX_SECCAO_LISTA 4

typedef struct {
	listaDpilha seccao[MAX_SECCAO_LISTA];
	int qtd;
} SECCOES;

SECCOES *criaSeccoes () {
	SECCOES *lista = (SECCOES *) malloc (sizeof (SECCOES));
	int i = 0;
	for (; i < MAX_SECCAO_LISTA; i++)
		lista->seccao[i] = *criaListaDpilha ();
	return lista;
}

int isVaziaSeccoes (SECCOES lista) {
	int i = 0;
	for (; i < MAX_SECCAO_LISTA; i++)
		if (!isVaziaListaPilha (lista.seccao[i])) return 0;
	return 1;
}

int isCheiaSeccoes (SECCOES lista) {
	int i = 0;
	for (; i < MAX_SECCAO_LISTA; i++)
		if (!isCheiaListaPilha (lista.seccao[i])) return 0;
	return 1;
}

int insereNseccao (SECCOES *lista, CONTENTOR c) {
	if (!isCheiaSeccoes (*lista)) {
		int i = 0;
		for (; i < MAX_SECCAO_LISTA; i++)
			if (insereNlistaDpilha (&lista->seccao[i], c)) return 1;
	}
	return 0;	
}

void listarSeccao (SECCOES lista) {
	if (isVaziaSeccoes (lista)) puts ("LISTA VAZIA!");
	else {
		int i = 0;
		puts ("SECCAO");
		puts ("_______________________________________________________");
		for (; i < MAX_SECCAO_LISTA; i++)
			puts ("------------------------------------------------------"),
			listaListaDpilha (lista.seccao[i]);
	}
}
