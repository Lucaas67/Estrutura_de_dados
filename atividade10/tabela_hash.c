#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

typedef struct HashNode {
    char* chave;
    char* dado;
    struct HashNode* proximo;
} HashNode;

static HashNode* tabela[TABLE_SIZE];

// Função hash simples que converte a chave em um índice do array
int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash = (hash + chave[i]) % TABLE_SIZE;
    }
    return hash;
}

void hash_table_init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    HashNode* atual = tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    HashNode* novo_node = (HashNode*)malloc(sizeof(HashNode));
    if (novo_node == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para o novo nó.\n");
        exit(1);
    }
    novo_node->chave = chave;
    novo_node->dado = dado;
    novo_node->proximo = tabela[index];
    tabela[index] = novo_node;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    HashNode* atual = tabela[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    HashNode* atual = tabela[index];
    HashNode* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela[index] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void hash_table_destroy() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* atual = tabela[i];
        while (atual != NULL) {
            HashNode* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
}