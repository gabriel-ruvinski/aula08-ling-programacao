// EXERCÍCIO 1: SISTEMA DE CALCULADORA MODULAR

#include <stdio.h>

void mostrarMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
}

int obterOpcao() {
    int op;
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

void obterNumeros(float *a, float *b) {
    printf("Digite o primeiro numero: ");
    scanf("%f", a);
    printf("Digite o segundo numero: ");
    scanf("%f", b);
}

float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: nao pode dividir por zero!\n");
        return 0;
    }
    return a / b;
}

void mostrarResultado(float resultado) {
    printf("Resultado: %.2f\n", resultado);
}

int main() {
    int opcao;
    float x, y, r;

    do {
        mostrarMenu();
        opcao = obterOpcao();
        if (opcao != 0) {
            obterNumeros(&x, &y);
        }
        switch(opcao) {
            case 1: r = somar(x, y); mostrarResultado(r); break;
            case 2: r = subtrair(x, y); mostrarResultado(r); break;
            case 3: r = multiplicar(x, y); mostrarResultado(r); break;
            case 4: r = dividir(x, y); if (y!=0) mostrarResultado(r); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    return 0;
}