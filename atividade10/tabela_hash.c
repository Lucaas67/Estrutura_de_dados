#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TABLE_SIZE 100

typedef struct Node {
    char* chave;
    char* dado;
    struct Node* prox;
} Node;

Node* table[TABLE_SIZE];

int hash(char* chave) {
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash += chave[i];
    }
    return hash % TABLE_SIZE;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);

    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->chave = strdup(chave);
    novo_node->dado = strdup(dado);
    novo_node->prox = NULL;

    if (table[index] == NULL) {
        table[index] = novo_node;
    } else {
        Node* atual = table[index];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_node;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->prox;
    }

    return NULL;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1; 
        }
        atual = atual->prox;
    }

    return 0; 
}

void hash_table_remove(char* chave) {
    int index = hash(chave);

    Node* atual = table[index];
    Node* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                table[index] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual->chave);
            free(atual->dado);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

