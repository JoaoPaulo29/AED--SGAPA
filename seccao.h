#include "listaDePilha.h"

//Estrutura da lista
typedef struct{
	ListaPilhas *lista[MAXLISTASECCAO];
	int qtd;
}Seccao;

Seccao *criarSeccao(){
	Seccao *seccao = (Seccao*)malloc(sizeof(Seccao));
	if (seccao){				
		int i;		
		for(i = 0; i < MAXLISTASECCAO; i++){
			seccao->lista[i] = criarListaPilhas();
			seccao->lista[i]->idLista = idSeccao++;
		}		
		return seccao;
	}
	return NULL;
}

int isSeccaoVazia(Seccao *seccao){	
	int i;
	for(i = 0; i < MAXLISTASECCAO; i++){
		if (!isListaPilhasVazia(seccao->lista[i])){
			return 0;
		}	
	}		
	return 1;
}

int isSeccaoCheia(Seccao *seccao){	
	int i;
	for(i = 0; i < MAXLISTASECCAO; i++){
		if (!isListaPilhasCheia(seccao->lista[i])){
			return 0;
		}	
	}
	return 1;
}

int entradaContentorSeccao(Seccao *seccao, Contentor *contentor){
	if (!isSeccaoCheia(seccao) && contentor != NULL){
			int j = 0;
			for (;j < MAXLISTASECCAO; j++){
				if (entradaContentorListas(seccao->lista[j], contentor)){			
					return 1;
				}	
			}
	}
	return 0;
}

Contentor *sairContentorSeccao(Seccao *seccao){
	int j = 0;
	for (;j < MAXLISTASECCAO; j++){
		if (!isListaPilhasVazia(seccao->lista[j])){
			return sairContentorLista(seccao->lista[j]);
		}
	}
	return NULL;
}

void listarSeccao(Seccao *seccao){
	if (!isSeccaoVazia(seccao)){
		int i;
		for(i = 0; i < MAXLISTASECCAO; i++){
			listarListaPilhas(seccao->lista[i]);	
			puts("---------------------------------------------------");
		}						
	}else puts("Lista vazia.");
}

void menuSeccao(Seccao *seccao, FilaContentores *filaContentor){
	putc("bhhhhhhhh");system("pause");
	char opcao;
	do{
		puts(".........MENU SECCAO..........");		
		puts("1 - Entrada de Contentor");
		puts("2 - Saida de Contentor");				
		puts("3 - Listar");
		puts("0 - Sair");
		fflush(stdin);
		scanf("%c", &opcao);
		system("cls");
		switch(opcao){			
			case '1':		
				puts("ENTRADA DE CONTENTOR");				
				fflush(stdin);
				printf("1 - NAVIO\n2 - CAMIAO\n");
				
				int op;
				fflush(stdin), scanf("%d", &op);
				if (op == 1){
					//NAVIO			
				}else if(op == 2){
					if (entradaContentorSeccao(seccao, saidaContentor(filaContentor))){
						puts("Entrada com sucesso.");
					}else{
						puts("Falha na entrada.");
					}
				}
				break;
			case '2':
				if (saidaContentor(filaContentor)){
					puts("Saida com sucesso.");
				}else{
					puts("Falha na saida");
				}				
				break;
			case '3':
				puts("LISTAR SECCOES");
				listarSeccao(seccao);
				break;
		}
		system("pause");
		system("cls");
	} while(opcao != '0');
	
}















