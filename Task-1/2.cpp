#include <stdio.h>
#include <string.h>

struct paciente {
	char nome[30];
	char profissao[30];
	int idade;
	char prioridade[15];
	
};

void alteraPrioridade ( struct paciente *p){
	
	if(strcmp(p->profissao, "medico")==0 && p->idade >= 60){
		strcpy(p->prioridade,"alta");
	} 
	else if(strcmp(p->profissao, "atendente")==0 && p->idade >= 60){
		strcpy(p->prioridade,"alta");
	}
	else if(strcmp(p->profissao, "motoboy")==0 && p->idade >= 60){
		strcpy(p->prioridade,"alta");
	}
	else if(strcmp(p->profissao, "enfermeiro")==0 && p->idade >= 60){
		strcpy(p->prioridade,"alta");
	}
	else if(strcmp(p->profissao, "motorista")==0 && p->idade >= 60){
		strcpy(p->prioridade,"alta");
	} 
	else{
		strcpy(p->prioridade,"desconhecida");
	}
	
		printf("\n\n\n______________________________");
		printf("\nFicha do paciente\n");
		printf("______________________________");
		printf("\nnome: %s\n", p->nome);
		printf("idade: %i \n", p->idade);
		printf("profissao: %s\n", p->profissao);
		printf("prioridade: %s\n", p->prioridade);
		
		
}



main(){
     
     struct paciente p;
     
	 	printf("Informe o nome do Paciente -> : ");
	    scanf("%s", p.nome);
	    
	    printf("\nInforme a idade do Paciente  -> : ");
	    scanf("%i", &p.idade);
	    
	    printf("\nInforme a profissao do Paciente -> : ");
	    scanf("%s", p.profissao);
	    
	    alteraPrioridade(&p);
	
	 
}
