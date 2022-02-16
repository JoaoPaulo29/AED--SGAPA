#include "seccao.h"

typedef struct porto{
	//FILA_NAVIOS navios;
	Seccao *seccoes;
	String nomePorto;
	int idPorto;
	FilaContentores *contentores;
	struct porto *proximo;
}Patio;

typedef struct {
	Patio *primeiro;
}Portos;

Patio *criarPorto(String nome){
	Patio *porto = (Patio*)malloc(sizeof(Patio));
	porto->seccoes = criarSeccao();
	porto->contentores = criarFilaContentor();
	strcpy(porto->nomePorto, nome);
	porto->proximo = NULL;
	porto->idPorto = ++qtdPorto;
	return porto;
}

Portos *criarPortos(){
	Portos *portos = (Portos*)malloc(sizeof(Portos));
	portos->primeiro = NULL;
	return portos;
}

int isPortosVaiza(Portos *portos){
	return portos->primeiro == NULL;
}

int inserirPorto(Portos *portos, Patio *porto){
	
	if (isPortosVaiza(portos)){
		portos->primeiro = porto;
		return 1;
	}else{
		Patio *aux = portos->primeiro;
		for(; aux->proximo != NULL; aux = aux->proximo);
		aux->proximo = porto;
		return 1;
	}
	return 0;	
}

Patio *verificarPorto(Portos *portos, int idPorto){
	Patio *aux = portos->primeiro;
	
	for (; aux != NULL; aux = aux->proximo){
		if (aux->idPorto == idPorto){
			return aux;
		}
	}	
	return NULL;	
}

int menuPorto(){
		Patio *porto = criarPorto("Luanda");
		char opcao;	
		do{
			puts(".........MENU PORTO..........");		
			puts("1 - Navios");
			puts("2 - Seccoes");				
			puts("3 - Camioes");
			puts("0 - Sair");
			fflush(stdin);
			scanf("%s", &opcao);
			//system("cls");
			switch(opcao){			
				case '1':		
					//menuNavio(porto->navios);
					break;
				case '2':
					menuSeccao(porto->seccoes, porto->contentores);
					break;
				case '3':
					menu(porto->contentores);
					break;
			}
			system("pause");
			system("cls");
		} while(opcao != '0');
		return 1;
		
	return 0;
	
} 

void listarPortos(Portos *portos){
	Patio *aux = portos->primeiro;
	puts("PORTOS");
	for(; aux != NULL; aux = aux->proximo){
		printf("ID: %d\n", aux->idPorto);
		printf("Nome: %s\n", aux->nomePorto);
		puts("----------------------------------------");
	}
}

void menuPrincipal(){
	Portos *portos = criarPortos();
	char opcao;
	int id;
	do{
		puts(".........MENU PORTO..........");		
		puts("1 - Novo");
		puts("2 - Eliminar");				
		puts("3 - Actualizar");
		puts("4 - Gerenciar porto");
		puts("5 - Listar");		
		puts("0 - Sair");
		fflush(stdin);
		scanf("%s", &opcao);
		system("cls");
		switch(opcao){			
			case '1':	
				puts("NOVO PORTO");	
				printf("Nome: ");
				String nomePorto;
				fflush(stdin), scanf("%s", &nomePorto);
				inserirPorto(portos, criarPorto(nomePorto));
				inserirPorto(portos, criarPorto(nomePorto));
				//menuNavio(porto->navios);
				break;
			case '2':
				//menuSeccao(portos->seccoes, porto->contentores);
				break;
			case '3':
				//menu(porto->contentores);
				break;
			case '4':				
				if (!isPortosVaiza(portos)){
					puts("GERENCIAR PORTO");
					printf("Informa ID: ");
					isInt = scanf("%d", &id);
					
					//menuPorto(verificarPorto(portos, id);
					/*	printf("Saindo do porto %s", verificarPorto(portos, id)->nomePorto);
					}else{
						puts("Falha ao entrar");
					}*/
				}else{
					puts("Deves criar um porto");
				}		
				
				break;
			case '5':
				listarPortos(portos);
				break;
		}
		system("pause");
		system("cls");
	} while(opcao != '0');
	
} 






