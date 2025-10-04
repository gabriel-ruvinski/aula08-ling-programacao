// EXERCÍCIO 3: MANIPULADOR DE STRINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lerString(char s[]) {
    printf("Digite uma string: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0'; // ele remove o \n
}

int contarCaracteres(const char s[]) {
    return strlen(s);
}

void inverterString(char s[]) {
    int i=0, j=strlen(s)-1;
    while(i<j) {
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++; j--;
    }
}

void paraMaiuscula(char s[]) {
    for(int i=0; s[i]; i++) s[i]=toupper(s[i]);
}

void paraMinuscula(char s[]) {
    for(int i=0; s[i]; i++) s[i]=tolower(s[i]);
}

int contarPalavras(const char s[]) {
    int count=0, inWord=0;
    for(int i=0; s[i]; i++) {
        if (!isspace(s[i]) && !inWord) {
            inWord=1; count++;
        } else if (isspace(s[i])) {
            inWord=0;
        }
    }
    return count;
}

int main() {
    char str[100];
    int opcao;

    lerString(str);

    do {
        printf("\n=== MANIPULADOR DE STRINGS ===\n");
        printf("1. Contar caracteres\n");
        printf("2. Inverter string\n");
        printf("3. Converter maiuscula\n");
        printf("4. Converter minuscula\n");
        printf("5. Contar palavras\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao); getchar();

        switch(opcao) {
            case 1: printf("A string possui %d caracteres.\n", contarCaracteres(str)); break;
            case 2: inverterString(str); printf("String invertida: %s\n", str); break;
            case 3: paraMaiuscula(str); printf("Maiuscula: %s\n", str); break;
            case 4: paraMinuscula(str); printf("Minuscula: %s\n", str); break;
            case 5: printf("Numero de palavras: %d\n", contarPalavras(str)); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opçao invalida!\n");
        }
    } while(opcao!=0);

    return 0;
}
