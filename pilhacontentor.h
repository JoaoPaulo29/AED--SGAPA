#include "contentor.h"
#define MAX_CONT_PILHA 2

typedef struct {
	CONTENTOR contentor [MAX_CONT_PILHA];
	int qtd;
} PILHA_CONT;

PILHA_CONT *cria_pilha_cont () {
	PILHA_CONT *pilha = (PILHA_CONT *) malloc (sizeof (PILHA_CONT));
	pilha->qtd = 0;
	return pilha;
}

int isVaziaPilhaCont (PILHA_CONT pilha) {
	return pilha.qtd == 0;
}

int isCheiaPilhaCont (PILHA_CONT pilha) {
	return pilha.qtd == MAX_CONT_PILHA;
}

int empilhar (PILHA_CONT *pilha, CONTENTOR cont) {
	if (isCheiaPilhaCont (*pilha)) return 0;
	pilha->contentor [pilha->qtd] = cont;
	pilha->qtd++;
	return 1;
}

int desempilha (PILHA_CONT *pilha) {
	if (isVaziaPilhaCont (*pilha)) return 0;
	pilha->qtd--;
	return 1;
}

void lista_pilha (PILHA_CONT pilha) {
	if (isVaziaPilhaCont (pilha)) puts ("PILHA VAZIA!");
	else {
		int i = 0;
		puts ("PILHA DE CONTENTORES");
		puts ("_______________________________________________________");
		for (; i < pilha.qtd; i++)
			puts ("------------------------------------------------------"),
			lista_cont (pilha.contentor[i]);
	}
}
