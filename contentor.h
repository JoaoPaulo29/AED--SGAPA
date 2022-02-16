#include "bibliotecaBasica.h"

//Estrutura do contentor
typedef struct contentor{	
	int idContentor;
	String nomeNavio;	
	struct contentor *proximo;
}Contentor;

//Estrutura da fila dos contentores
typedef struct{
	Contentor *primeiro, *ultimo;	
}FilaContentores;

FilaContentores *criarFilaContentor(){
	FilaContentores *fila = (FilaContentores*)malloc(sizeof(FilaContentores));
	if (fila){
		fila->primeiro = fila->ultimo = NULL;
		return fila;
	}
	return NULL;
}

Contentor *criarContentor(String nomeNavio){
	Contentor *contentor = (Contentor*)malloc(sizeof(Contentor));
	if (contentor){		
		strcpy(contentor->nomeNavio, nomeNavio);
		contentor->proximo = NULL;
		contentor->idContentor = ++gerarIdContentor;
		return contentor;
	}
	return NULL;
}

int contaContentorFila(FilaContentores *fila){
	int i = 0;
	Contentor *aux = fila->primeiro;
	for (; aux != NULL; i++, aux = aux->proximo);
	return i;
}

int isFilaContentorVazia(FilaContentores *fila){
	return fila->primeiro == NULL;
}

int isFilaContentorCheia(FilaContentores *fila){
	return contaContentorFila(fila) == MAXCONTENTOR;
}

int entradaContentor(FilaContentores *fila, Contentor *contentor){
	if (!isFilaContentorCheia(fila) && contentor != NULL){
		if (isFilaContentorVazia(fila)){			
			fila->primeiro = fila->ultimo = contentor;
		}else{
			fila->ultimo->proximo = contentor;
			fila->ultimo = contentor;
		}		
		return 1;		
	}
	return 0;
}

int actualizarContentor(FilaContentores *fila, int id, String nomeNavio){
	if (!isFilaContentorVazia(fila)){
		Contentor *aux = fila->primeiro;		
		for (; aux->proximo != NULL && aux->idContentor != id ; aux = aux->proximo);		
		strcpy(aux->nomeNavio, nomeNavio);		
		return 1;		
	}
	return 0;
}


Contentor *saidaContentor(FilaContentores *fila){
	if (!isFilaContentorVazia(fila)){
		Contentor *aux = fila->primeiro; 
		if (aux->proximo == NULL){
			fila->primeiro = fila->ultimo = NULL;			
		}else{
			fila->primeiro = aux->proximo;			
		}		
		return aux;
	}
	return NULL;
}

void mostraContentor(Contentor *contentor){
	printf("ID: %d\nNome: %s\n",contentor->idContentor, contentor->nomeNavio);
}

void listarFilaContentor(FilaContentores *fila){
	if (!isFilaContentorVazia(fila)){
		Contentor *aux = fila->primeiro;
		for (; aux != NULL; aux = aux->proximo)
			mostraContentor(aux),
			puts("---------------------------------------------------");	
	}else puts("Lista vazia.");
}

void menu(FilaContentores *fila){	
	char opcao;
	do{
		puts(".........MENU CONTENTOR..........");		
		puts("1 - Entrada");
		puts("2 - Saida");		
		puts("3 - Actualizar");
		puts("4 - Listar");
		puts("0 - Sair");
		fflush(stdin);
		scanf("%s", &opcao);
		system("cls");
		switch(opcao){			
			case '1':		
				puts("ENTRADA");				
				fflush(stdin);
				printf("Nome: ");
				scanf("%s",nomeNavio);								
				if (entradaContentor(fila, criarContentor(nomeNavio))){
					puts("Entrada com sucesso.");
				}else{
					puts("Falha na entrada");
				}				
				break;
			case '2':
				if (saidaContentor(fila)){
					puts("Saida com sucesso.");
				}else{
					puts("Falha na saida");
				}				
				break;
			case '3':
				puts("ACTUALIZAR\n");			
				fflush(stdin);
				printf("Nome: ");
				scanf("%s",nomeNavio);								
				printf("ID: ");
				scanf("%d", &idContentor);
				if (actualizarContentor(fila, idContentor, nomeNavio)){
					puts("Entrada com sucesso.");
				}else{
					puts("Falha na entrada");
				}
				
				break;
			case '4':				
				puts("MOSTRAR FILA DE CONTENTORES\n");
				listarFilaContentor(fila);
				break;
		}
		system("pause");
		system("cls");
	} while(opcao != '0');
}
