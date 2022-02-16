#include "pilha.h"

//Estrutura da lista
typedef struct{
	PilhaContentores *pilha[MAXPILHALISTASECCAO];
	char idLista;
	int qtd;
}ListaPilhas;

ListaPilhas *criarListaPilhas(){
	ListaPilhas *lista = (ListaPilhas*)malloc(sizeof(ListaPilhas));
	if (lista){				
		int i;
		for(i = 0; i < MAXPILHALISTASECCAO; i++){
			lista->pilha[i] = criarPilhaContentor();
		}		
		return lista;
	}
	return NULL;
}

int isListaPilhasVazia(ListaPilhas *lista){	
	int i;
	for(i = 0; i < MAXPILHALISTASECCAO; i++){
		if (!isPilhaContentorVazia(lista->pilha[i])){
			return 0;
		}	
	}		
	return 1;
}

int isListaPilhasCheia(ListaPilhas *lista){	
	int i;
	for(i = 0; i < MAXPILHALISTASECCAO; i++){
		if (!isPilhaContentorCheia(lista->pilha[i])){
			return 0;
		}	
	}
	return 1;
}

int menorPilhaLista(ListaPilhas *lista){
	if (!isListaPilhasVazia(lista)){
		int i;
		for (i = 0, menor = contaContentorPilha(lista->pilha[i]); i < MAXPILHALISTASECCAO; i++)
			if (menor < contaContentorPilha(lista->pilha[i]))
				menor = contaContentorPilha(lista->pilha[i]),fflush(stdin),
				posicao = i;
		return posicao+1;
	}
	return 0;
}

int entradaContentorListas(ListaPilhas *lista, Contentor *contentor){
	if (!isListaPilhasCheia(lista) && contentor != NULL){
			int j = 0;
			for (;j < MAXPILHALISTASECCAO; j++){
				if (empilhar(lista->pilha[j], contentor)){													
					return 1;
				}	
			}
	}
	return 0;
}

Contentor *sairContentorLista(ListaPilhas *lista){
	int j = 0;
	for (;j < MAXPILHALISTASECCAO; j++){
		if (!isPilhaContentorVazia(lista->pilha[j])){
			return desempilhar(lista->pilha[j]);
		}
	}
	return NULL; 
}

void listarListaPilhas(ListaPilhas *lista){
	if (!isListaPilhasVazia(lista)){
		int i;
		printf("Seccao: %c\n", lista->idLista);
		for(i = 0; i < MAXPILHALISTASECCAO; i++){						
			listarPilhaContentor(lista->pilha[i]);	
			puts("---------------------------------------------------");
		}						
	}else printf("Seccao: %c\n", lista->idLista), puts("Lista vazia.");
}
