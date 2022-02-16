#include<stdio.h>
#include<stdlib.h>
#include "string.h"

#define MAXCONTENTOR 4
#define MAXCONTENTORPILHASECCAO 2
#define MAXPILHASECCAO 4
#define MAXPILHALISTASECCAO 2
#define MAXLISTASECCAO 4

typedef char String[30];
int gerarIdContentor = 0;

String nomeNavio;
int idContentor;

int idPilha = 0, menor, posicao;

char idSeccao = 'A';
int qtdPorto=0;

int isInt = 0;

int k = 0;
int quantidade;
