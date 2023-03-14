#include <stdio.h>
#include <windows.h>

struct pessoa{
	float peso;
	float altura;
	int idade;
	float imc;	
};


float calculaImc (struct pessoa *lista){
	float media = 0;
	float somaImc =0;
	
	for(int i = 0; i < 3 ; i++){
		lista[i].imc = lista[i].peso /  (lista[i].altura * lista[i].altura );
		somaImc += lista[i].imc;
	}
	media = (somaImc/3);
	
	return media;
	
} 
main(){
	
	float mediaImc = 0;	
	struct pessoa lista[3];
	
	for(int j=0 ; j < 3; j++){
		printf("\nInforme a idade da pessoa %i\n", j);
		scanf("%f",&lista[j].idade);
		
		printf("Informe a altura da pessoa %i\n", j);
		scanf("%f",&lista[j].altura);
		
		printf("Informe o peso da pessoa %i\n", j);
		scanf("%f",&lista[j].peso);
		printf("_____________________________");
	}
		mediaImc = calculaImc(lista);
		
		printf("\nA media IMC geral e %.2f\n", mediaImc);
		system("pause");
}
