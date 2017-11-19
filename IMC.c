#include<stdio.h>
#include<stdlib.h>

struct tpessoa {
	float peso,altura;
	char nome,bairro;
}pessoa;

int main(){
	int imc;
	char perg;
	struct tpessoa pessoa[3];
	
	for(int i=0;i<3;i++){
		printf("digite o peso");
		scanf("%f",&pessoa[i].peso);
		setbuf(stdin,NULL);	
		printf("digite o altura");
		scanf("%f",&pessoa[i].altura);
		setbuf(stdin,NULL);
		printf("digite o nome");
		scanf("%c",&pessoa[i].nome);
		setbuf(stdin,NULL);
		printf("digite o bairro");
		scanf("%c",&pessoa[i].bairro);
		setbuf(stdin,NULL);
	}
	printf("digite o bairro que voce deseja saber o estado das pessoas");
	scanf("%c",&perg);
	for (int j=0;j<3;j++){
		imc=pessoa[j].peso/pessoa[j].altura*2;
		if (pessoa[j].bairro == perg){
			if (imc>18.25){
				printf("abaixo do peso");
			}else {
				printf("acima do peso");
			}
		}
	}
	system("pause");
}
