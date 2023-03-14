#include <stdio.h>


void funcPreenche (int* px){
	int i=1;
	for(i; i <= 10; i++, px++){
		scanf("%d\n", px);
	}
	
}


int main (){
	
	int valor[10];
	int i;
	funcPreenche(valor);

	for(i = 0; i< 10; i++){
	printf("%d\n", valor[i]);
	}
	 
}
