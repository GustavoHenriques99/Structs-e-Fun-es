#include <stdio.h>

struct Aluno {
	char nome[30];
	int matricula;
	float notas[3];
    float media;
};

int qtdeAluno = 0;

void entradaDados(struct Aluno A1[10]){
    do {
        printf("Quantos alunos? (maximo 10): ");
        scanf("%d", &qtdeAluno);

        if (qtdeAluno < 1 || qtdeAluno > 10) {
            printf("Erro! digite um valor entre 1 e 10.\n");
        }
    } while (qtdeAluno < 1 || qtdeAluno > 10);
	
	for(int i = 0; i < qtdeAluno; i++){

		//Cadastro nome dos alunos.
		printf("\nAluno - %d\n", i+1);

		printf("Nome do Aluno: ");
		scanf("%s", A1[i].nome);
		
		//Cadastro Matricula.
		printf("Matricula: ");
		scanf("%d", &A1[i].matricula);
		
		//Cadastro Notas.
		for(int j = 0; j < 3; j++){
			printf("%d - Nota: ", j+1);
			scanf("%f", &A1[i].notas[j]);
		}
	}
}


void calcMedia(struct Aluno A1[10]){

    float somaNota[10];
	float media = 0;

	//media
	for (int i = 0; i < qtdeAluno; i++) {
        somaNota[i] = 0;

        for (int j = 0; j < 3; j++) {
            if (j == 0 || j == 1){
                somaNota[i] += (A1[i].notas[j] * 3);
           	} else{somaNota[i] += (A1[i].notas[j] * 4);}
        }

	    A1[i].media = somaNota[i] / 10; 
	    printf("\nMedia do aluno %d = %.2f\n", i + 1, A1[i].media);
    }

}

void exibirResultados(struct Aluno A1[10]) {
    printf("\n--- Aprovados ---\n");
    for (int i = 0; i < qtdeAluno; i++) {
        if (A1[i].media >= 7.0) {
            printf("%s (%d) - M�dia: %.2f\n", A1[i].nome, A1[i].matricula, A1[i].media);
        }
    }

    printf("\n--- Exame ---\n");
    for (int i = 0; i < qtdeAluno; i++) {
        if (A1[i].media >= 4.0 && A1[i].media < 7.0) {
            printf("%s (%d) - Media: %.2f\n", A1[i].nome, A1[i].matricula, A1[i].media);
        }
    }

    printf("\n--- Reprovados ---\n");
    for (int i = 0; i < qtdeAluno; i++) {
        if (A1[i].media < 4.0) {
            printf("%s (%d) - Media: %.2f\n", A1[i].nome, A1[i].matricula, A1[i].media);
        }
    }
}

int main(){
    
	struct Aluno A1[30];
    
	entradaDados(A1);
	calcMedia(A1);
    exibirResultados(A1);

}
