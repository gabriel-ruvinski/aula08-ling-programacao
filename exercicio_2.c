// EXERCÍCIO 2: ANÁLISE DE ARRAY

#include <stdio.h>
#define TAM 10

void preencherArray(int v[], int n) {
    for (int i=0; i<n; i++) {
        printf("Numero %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

void exibirArray(const int v[], int n) {
    printf("[");
    for (int i=0; i<n; i++) {
        printf("%d", v[i]);
        if (i<n-1) printf(", ");
    }
    printf("]\n");
}

int maiorValor(const int v[], int n) {
    int m = v[0];
    for (int i=1; i<n; i++) if (v[i] > m) m = v[i];
    return m;
}

int menorValor(const int v[], int n) {
    int m = v[0];
    for (int i=1; i<n; i++) if (v[i] < m) m = v[i];
    return m;
}

float media(const int v[], int n) {
    int soma=0;
    for (int i=0; i<n; i++) soma+=v[i];
    return (float)soma/n;
}

void ordenarArray(int v[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (v[i]>v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int vetor[TAM];
    printf("-- Insira 10 numeros: \n");
    preencherArray(vetor, TAM);

    printf("Array original: ");
    exibirArray(vetor, TAM);

    printf("Maior valor: %d\n", maiorValor(vetor, TAM));
    printf("Menor valor: %d\n", menorValor(vetor, TAM));
    printf("Media: %.2f\n", media(vetor, TAM));

    ordenarArray(vetor, TAM);
    printf("Array ordenado: ");
    exibirArray(vetor, TAM);

    return 0;
}
