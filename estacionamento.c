#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define QNT_VAGAS 10
#define PRECO_DIARIA 60
#define PRECO_2HORA 8
#define PRECO_DHORA 2

typedef struct regCarro {
	char placa[8];
	int dia[3];
	int hora[2];
	int usado;
} RegCarro;

void entrar(RegCarro registro[]);
void sair(RegCarro registro[]);
void calcular(RegCarro registro, RegCarro temp);
long int getMin(RegCarro saida, RegCarro entrada);

int main() {
	int menu, i = 0;
	setlocale(LC_ALL, "Portuguese");
	
	RegCarro registro[QNT_VAGAS];

	FILE *arq = fopen("registro.dat", "r");

	if (arq != NULL) {
		while (!feof(arq)) {
			fread(&registro[i], sizeof(RegCarro), 1, arq);
			i++;
		}
		while (i < QNT_VAGAS) {
			registro[i].usado = 0;
			i++;
		}
	} else {
		for(i = 0; i < QNT_VAGAS; i++) {
			registro[i].usado = 0;
		}
	}

	fclose(arq);
	
	printf("--- BEM VINDO AO ESTACIONAMENTO LP ---\n");
	do {
		printf("\n1. Entrar no estacionamento\n");
		printf("2. Sair do estacionamento\n");
		printf("3. Mostrar preços\n");
		printf("4. Fechar programa\n");
		
		scanf("%d", &menu);
		
		switch(menu) {
			case 1:
				entrar(registro);			
				break;
			case 2:
				sair(registro);
				break;
			case 3:
				printf("\nPreços:\n");
				printf("- Cortesia de até 10 minutos\n");
				printf("- Até 2 horas: R$8,00\n");
				printf("- Hora adicional: R$2,00\n");
				printf("- Diária: R$60,00\n");
				break;
		}	
	} while(menu != 4);

	arq = fopen("registro.dat", "w");

	i = 0;
	while (i < QNT_VAGAS) {
		if (registro[i].usado == 1) {
			fwrite(&registro[i], sizeof(RegCarro), 1, arq);
		}
		i++;
	}

	fclose(arq);

	return 0;
}

void entrar(RegCarro registro[]) {
	int i = 0;

	while (registro[i].usado != 0 && i < QNT_VAGAS)
		i++;

	if (i == QNT_VAGAS) {
		printf("Estacionamento LOTADO\n");
	} else {
		printf("- Digite sua placa no formato XXX-9999\n");
		scanf("%s", registro[i].placa);

		printf("- Digite a data no formato DD/MM/AAAA\n");
		scanf("%d/%d/%d", &registro[i].dia[0], &registro[i].dia[1], &registro[i].dia[2]);

		printf("- Digite o horário no formato HH:MM\n");
		scanf("%d:%d", &registro[i].hora[0], &registro[i].hora[1]);

		printf("Cadastro Realizado Com Sucesso\n");
		registro[i].usado = 1;
	}
}

void sair(RegCarro registro[]) {
	RegCarro temp;
	int i = 0;

	printf("- Digite sua placa no formato XXX-9999\n");
	scanf("%s", temp.placa);

	printf("- Digite a data no formato DD/MM/AAAA\n");
	scanf("%d/%d/%d", &temp.dia[0], &temp.dia[1], &temp.dia[2]);

	printf("- Digite o horário no formato HH:MM\n");
	scanf("%d:%d", &temp.hora[0], &temp.hora[1]);

	while((strcmp(registro[i].placa, temp.placa) == 0 && i < QNT_VAGAS) || registro[i].usado == 0) {
		i++;
	}

	if (i == QNT_VAGAS || registro[i].usado == 0) {
		printf("CARRO NÃO ENCONTRADO!\n");
	} else {
		calcular(registro[i], temp);
		printf("Saída Realizada Com Sucesso\n");
		registro[i].usado = 0;
	}
}

long int getMin(RegCarro saida, RegCarro entrada) {
	long int dataSaida, dataEntrada;
	long int minSaida, minEntrada;

	dataSaida = saida.dia[2]*365 + saida.dia[1]*30 + saida.dia[0];
	dataEntrada = entrada.dia[2]*365 + entrada.dia[1]*30 + entrada.dia[0];

	minSaida = saida.hora[0]*60 + saida.hora[1] + dataSaida*1440;
	minEntrada = entrada.hora[0]*60 + entrada.hora[1] + dataEntrada*1440;

	return minSaida-minEntrada;
}

void calcular(RegCarro registro, RegCarro temp){
	long int dif = getMin(temp, registro);
	int diaria = (int) dif/1440;
	int restDiaria = (int) dif%1440;

	float preco = diaria*PRECO_DIARIA;
	int horas = ceil(restDiaria/60.0);
	if (restDiaria > 0) {
		preco += PRECO_2HORA;
		horas -= 2;
		if (horas < 0)
			horas = 0;
	}

	preco += horas*PRECO_DHORA;

	if (dif <= 10) {
		printf("Horário dentro da tolerância inicial!\n");
	} else {
		printf("Valor a pagar: R$%.2f\n", preco);
	}
}
