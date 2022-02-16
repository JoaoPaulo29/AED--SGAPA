#include "porto.h"

void menu_main(){
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
		switch(opcao){			
			case '1':	
				puts("NOVO PORTO");	
				printf("Nome: ");
				String nomePorto;
				fflush(stdin), scanf("%s", &nomePorto);
				inserirPorto(portos, criarPorto(nomePorto));
				break;
			case '2':
				
				break;
			case '3':				
				
				break;
			case '4':				
				if (!isPortosVaiza(portos)){
					puts("GERENCIAR PORTO");
					printf("Informa ID: ");
					isInt = scanf("%d", &id);
					
					if (menuPorto(verificarPorto(portos, id))){
						printf("Saindo do porto %s", verificarPorto(portos, id)->nomePorto);
					}else{
						puts("Falha ao entrar");
					}
				}else{
					puts("Deves criar um porto");
				}		
				
				break;
			case '5':
				listarPortos(portos);
				break;
		}
		system("pause");
	} while(opcao != '0');
}
