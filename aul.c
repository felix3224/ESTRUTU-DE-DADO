#include <stdio.h>
#include <stdlib.h>

void imprime(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int comprimento(char* s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        n++;
    }
    return n;
}

void copiar(char* dest, char* orig) {
    int i;
    for (i = 0; orig[i] != '\0'; i++) {
        dest[i] = orig[i];
    }
    dest[i] = '\0'; // Adiciona o caractere nulo no final da string
    imprime(dest);
}

int main(void) {
    char name[50];
    scanf(" %49[^\n]", name);

    int qtd = comprimento(name);
    printf("O comprimento da string e: %d\n", qtd);

    char* c = (char*)malloc((comprimento(name) + 1) * sizeof(char));
    if (c == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    copiar(c, name);

    free(c); // Libera a memória alocada
    return 0;
}