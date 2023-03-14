#include <stdio.h>

void calcularSalariosLiquidos(float *salarios, int n) {
   
   
    for (int i = 0; i < n; i++) {
        printf("informe o salario do funcionario - %d\n ", i);
        scanf("%f", &salarios[i]);
		salarios[i] *= 0.92; 
    }
}

int main() {
    float salarios[10]; 
    int n = sizeof(salarios) / sizeof(float); //tamanho do vetor
    calcularSalariosLiquidos(salarios, n);
   

    printf("Salarios liquidos:\n");
    for (int i = 0; i < n; i++) {
        printf("\n funcionario %d : %.2f\n", i, salarios[i]);
    }

    return 0;
}
