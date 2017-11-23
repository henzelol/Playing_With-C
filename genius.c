#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void umJogador();
void doisJogadores();
void gerarValores(int vet[], int count);

void tempo(int seg);

main() {
	int x;
	
	printf("--- BEM VINDO AO JOGO GENIUS ---\n");
	
	do {
		printf("Deseja jogar como?\n");
		printf("1. Um jogador\n");
		printf("2. Dois jogadores\n"); Botei do jeito q dalforno especificou
		printf("3. Sair\n");
		
		scanf("%d", &x);
		
		switch(x) {
			case 1:
				umJogador();
				break;
			case 2:
				doisJogadores();
				break;
		}
	} while(x != 3);
	
}


void umJogador() {
	int level = 1, lost = 0, j , k, count = 0, num[10], y;
	
	while (lost == 0) {
		if (level == 1)
			printf("O jogo comecou:\n");
		else
			printf("Voce passou para o proximo nivel:\n");

		gerarValores(num, count);
			
		printf("\n");
		for (j = 1; j <= 10 && lost == 0; j++) {
tempo(2); Para ter tempo de mudra a tela e aparecer o numero(antes tava mto rapido)
			for (k = 0; k < j; k++) {
				printf("%d", num[k]);
				tempo(1);
				printf("\b* ");	
			}
			printf("\n");
			

			for (k = 0; k < j && lost == 0; k++) {
				scanf("%d", &y);
				if(y != num[k]) {
					lost = 1;
				}
			}
			system("cls");
		}
		if (lost == 1)
			printf("Voce perdeu e parou no nivel %d!\n-----------------------------\n", level);
		if (j >= 10) {
			level++;
			count += 3;
		}
	}
}





void doisJogadores() {
	int level = 1, lost = 0, j , k, count = 0, jog = 1, num[10], y;
	
	while (lost == 0) {
		if (level == 1)
			printf("O jogo comecou:\n");
		else
			printf("Voces passaram para o proximo nivel:\n");

		gerarValores(num, count);

		printf("\n");
		for (j = 1; j <= 10 && lost == 0; j++) {
			printf("Vez do jogador %d:\n", jog);
tempo(2); Para ter tempo de mudra a tela e aparecer o numero(antes tava mto rapido)

			for (k = 0; k < j; k++) {
				printf("%d", num[k]);
				tempo(1);
				printf("\b* ");
				
			}
			printf("\n");
			

			for (k = 0; k < j && lost == 0; k++) {
				scanf("%d", &y);
				if(y != num[k]) {
					lost = 1;
				}
			}

			system("cls");

			jog++;
			if (jog > 2)
				jog = 1;
		}
		if (lost == 1) 
			printf("O jogador %d ganhou!\n---------------------------------------------\n", jog);
		if (j >= 10) {
			level++;
			count += 3;
		}
	}	
}

void tempo(int seg) {
    int tQ = time(NULL) + seg;
    while (time(NULL) < tQ);
}

void gerarValores(int vet[], int count) {
	int k, r;

	srand(time(NULL));
	for (k = 0; k < 10; k++) {
		r = (rand() % (3+count)) + 1;
		vet[k] = r;
	}
}
