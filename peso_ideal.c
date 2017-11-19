#include<stdio.h>
#include<stdlib.h>

void peso(float altura,char sexo,float atual){
	float peso;
	
	if (sexo == 'M' || 'm') {
		   peso=altura*72.7-58;
	} else if (sexo == 'F' || 'f'){
			peso=altura*62.1-44.7;
	}
	else{
		printf("sexo incorreto");
	 }
	 printf(" seu peso ideal é de :%.2f Kilos \n",peso);
	if (atual > peso){
		   	printf("voce esta acima do peso");
	} else if (atual == peso){
			printf("voce esta com o peso ideal");
	} else {
			printf("voce esta abaixo do peso");
		}
 }


int main(){
	char sexo;
	float altura,atual;
	
	printf("digite sua altura em metros\n");
	scanf("%f",&altura);
	setbuf(stdin,NULL);
	printf("agora digite seu sexo \t M = masculino \t f = feminino\n");
	scanf("%c", &sexo);
	setbuf(stdin,NULL);
	printf("digite seu peso\n");
	scanf("%f",&atual);
	setbuf(stdin,NULL);
	peso(altura,sexo,atual);
	
	
	system("pause");
}
