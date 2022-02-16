#include "contentor.h"

//Estrutura da pilha dos contentores
typedef struct{
	Contentor *topo;
}PilhaContentores;

PilhaContentores *criarPilhaContentor(){
	PilhaContentores *pilha = (PilhaContentores*)malloc(sizeof(PilhaContentores));
	if (pilha){
		pilha->topo = NULL;
		return pilha;
	}
	return NULL;
}

int contaContentorPilha(PilhaContentores *pilha){
	int i = 0;
	Contentor *aux = pilha->topo;
	for (; aux != NULL; i++, aux = aux->proximo);
	return i;
}

int isPilhaContentorVazia(PilhaContentores *pilha){
	return pilha->topo == NULL;
}

int isPilhaContentorCheia(PilhaContentores *pilha){
	return contaContentorPilha(pilha) == MAXCONTENTORPILHASECCAO;
}

int empilhar(PilhaContentores *pilha, Contentor *contentor){	
	if (!isPilhaContentorCheia(pilha) && contentor != NULL){		
		contentor->proximo = pilha->topo;		
		pilha->topo = contentor;		
		return 1;		
	}
	return 0;
}

Contentor *desempilhar(PilhaContentores *pilha){
	if (!isPilhaContentorVazia(pilha)){
		Contentor *aux = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		return aux;
	}
	return NULL;
}

void listarPilhaContentor(PilhaContentores *pilha){
	if (!isPilhaContentorVazia(pilha)){
		Contentor *aux = pilha->topo;
		for (; aux != NULL; aux = aux->proximo)
			mostraContentor(aux),
			puts("---------------------------------------------------");	
	}else puts("Pilha vazia.");
}
