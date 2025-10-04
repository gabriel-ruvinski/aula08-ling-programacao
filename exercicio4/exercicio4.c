// EXERCÍCIO 4: SISTEMA DE GESTÃO DE NOTAS

#include <stdio.h>
#define ALUNOS 5
#define DISCIPLINAS 4

void inserir_notas(float notas[][DISCIPLINAS]) {
    for(int i=0;i<ALUNOS;i++){
        printf("Aluno %d:\n", i+1);
        for(int j=0;j<DISCIPLINAS;j++){
            printf("  Nota da disciplina %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
}

void exibir_notas(const float notas[][DISCIPLINAS]) {
    printf("\nMATRIZ DE NOTAS:\n");
    for(int i=0;i<ALUNOS;i++){
        printf("Aluno %d: ", i+1);
        for(int j=0;j<DISCIPLINAS;j++){
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }
}

float calcular_media_aluno(const float notas[][DISCIPLINAS], int aluno) {
    float soma=0;
    for(int j=0;j<DISCIPLINAS;j++) soma+=notas[aluno][j];
    return soma/DISCIPLINAS;
}

float calcular_media_disciplina(const float notas[][DISCIPLINAS], int disciplina) {
    float soma=0;
    for(int i=0;i<ALUNOS;i++) soma+=notas[i][disciplina];
    return soma/ALUNOS;
}

void exibir_relatorio_final(const float notas[][DISCIPLINAS]) {
    for(int i=0;i<ALUNOS;i++){
        float media = calcular_media_aluno(notas, i);
        printf("Aluno %d - Media: %.2f - %s\n", i+1, media, (media>=6.0?"Aprovado":"Reprovado"));
    }
}

int main() {
    float notas[ALUNOS][DISCIPLINAS] = {0};
    int opcao, notas_inseridas = 0;

    do {
        printf("\n=== SISTEMA DE NOTAS ===\n");
        printf("1. Inserir notas\n");
        printf("2. Exibir notas\n");
        printf("3. Media por aluno\n");
        printf("4. Media por disciplina\n");
        printf("5. Relatorio final\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: inserir_notas(notas); notas_inseridas = 1; break;
            case 2: 
                if (notas_inseridas) exibir_notas(notas);
                else printf("Insira as notas primeiro!\n");
                break;
            case 3: {
                int a; printf("Aluno (1-%d): ", ALUNOS); scanf("%d",&a);
                if (a < 1 || a > ALUNOS) printf("Aluno inexistente!\n");
                else printf("Media aluno %d = %.2f\n", a, calcular_media_aluno(notas,a-1));
                break;
            }
            case 4: {
                int d; printf("Disciplina (1-%d): ", DISCIPLINAS); scanf("%d",&d);
                if (d < 1 || d > DISCIPLINAS) printf("Disciplina inexistente!\n");
                else printf("Media disciplina %d = %.2f\n", d, calcular_media_disciplina(notas,d-1));
                break;
            }
            case 5: 
                if (notas_inseridas) exibir_relatorio_final(notas);
                else printf("Insira as notas primeiro!\n");
                break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao!=0);

    return 0;
}
