#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso correto: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int num_words = 0;

    while (fgets(words[num_words], MAX_WORD_LENGTH, input_file) != NULL) {
        words[num_words][strlen(words[num_words]) - 1] = '\0'; // Remover o caractere de nova linha
        num_words++;
    }

    fclose(input_file);

    bubble_sort(words, num_words);

    FILE *output_file = fopen("arq_palavras_ordenado.txt", "w");
    if (output_file == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\n", words[i]);
    }

    fclose(output_file);

    printf("Palavras ordenadas e salvas em 'arq_palavras_ordenado.txt'\n");

    return 0;
}
