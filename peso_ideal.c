#include<stdio.h>
#include<stdlib.h>

void peso(float altura,char sexo){
	float peso;
	
	if (sexo == 'M' || 'm') {
		   peso=altura*72.7-58;
	} else if (sexo == 'F' || 'f'){
			peso=altura*62.1-44.7;
	}
	else{
		printf("sexo incorreto");
	 }
	 printf(" seu peso ideal é de :%.2f Kilos ",peso);
}

int main(){
	char sexo;
	float altura;
	
	printf("digite sua altura em metros\n");
	scanf("%f",&altura);
	setbuf(stdin,NULL);
	printf("agora digite seu sexo \t M = masculino \t f = feminino\n");
	scanf("%c", &sexo);
	setbuf(stdin,NULL);
	peso(altura,sexo);
	system("pause");
}
