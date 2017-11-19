#include<stdio.h>

#include<stdlib.h>



struct tpessoa {

	char nome[20];

	unsigned short int idade;

};







int main()

{

int cont=0,media;

struct tpessoa v[3];



for (int i=0;i<3;i++){

	printf("digite o nome da pessoa");

	scanf("%s", v[i].nome);

	printf("digite a idade");

	scanf("%",v[i].idade);

	cont+=v[i].idade;

}

media=cont/3;



for (int j=0;j<3;j++){

	

	if (v[j].idade>media){

		printf("a pessoa %s esta acima da media",v[j].nome);

	}	

}	

	return 0;

}
