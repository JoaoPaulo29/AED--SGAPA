#include "pilha.h"

//Estrutura do contentor
typedef struct pilha{
	int idPilha;
	PilhaContentores *pilha;
	struct pilha *proximo;
}Pilha;

//Estrutura da lista
typedef struct{
	Pilha *primeira;	
}ListaPilhas;

Pilha *criarPilha () {
	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
	pilha->idPilha = idPilha++;
	pilha->pilha = criarPilhaContentor();
	pilha->proximo = NULL;
	return pilha;	
}

ListaPilhas *criarListaPilhas(){
	ListaPilhas *lista = (ListaPilhas*)malloc(sizeof(ListaPilhas));
	if (lista){
		lista->primeira = criarPilha();
		Pilha *aux;	
		for (i = 0; i++ < MAXPILHASECCAO; aux = criarPilha(), aux->proximo = lista->primeira, lista->primeira = aux)	
		return lista;
	}
	return NULL;
}

int isListaPilhasVazia(ListaPilhas *lista){
	Pilha *aux = lista->primeira;
	for (; aux != NULL; aux = aux->proximo)
		if (!isPilhaContentorVazia(aux->pilha))
			return 0;
	return 1;
}

int isListaPilhasCheia(ListaPilhas *lista){	
	Pilha *aux = lista->primeira;
	for (; aux != NULL; aux = aux->proximo)
		if (!isPilhaContentorCheia(aux->pilha))
			return 0;
	return 1;
}

int menorPilhaLista(ListaPilhas *lista){
	if (!isListaPilhasVazia(lista)){
		Pilha *aux = lista->primeira;
		for (menor = contaContentorPilha(aux->pilha); aux != NULL; aux = aux->proximo)
			if (menor < contaContentorPilha(aux->pilha))
				menor = contaContentorPilha(aux->pilha),
				posicao = aux->idPilha;
		return posicao+1;
	}
	return 0;
}

int entradaContentorListas(ListaPilhas *lista, Contentor *contentor){
	if (!isListaPilhasCheia(lista) || contentor != NULL){		
		if (!menorPilhaLista(lista)){
			int indice = menorPilhaLista(lista);
			Pilha *aux = lista->primeira;
			for (; indice != aux->idPilha; aux = aux->proximo);
			empilhar(aux->pilha, contentor);
			return 1;
		}		
	}
	return 0;
}


void listarListaPilhas(ListaPilhas *lista){
	if (!isListaPilhasVazia(lista)){
		Pilha *aux = lista->primeira;
		for (; aux != NULL; aux = aux->proximo)
			listarPilhaContentor(aux->pilha),
			puts("---------------------------------------------------");	
	}else puts("Lista vazia.");
}
