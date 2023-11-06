#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    // Implementação da função de inserção
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // Implementação da função de exclusão
}

int search(struct TreeNode* root, int key) {
    // Implementação da função de busca
}

void inorder(struct TreeNode* root) {
    // Implementação da função de percurso inorder
}

void preorder(struct TreeNode* root) {
    // Implementação da função de percurso preorder
}

void postorder(struct TreeNode* root) {
    // Implementação da função de percurso postorder
}

int findMin(struct TreeNode* root) {
    // Implementação da função para encontrar o valor mínimo
}

int findMax(struct TreeNode* root) {
    // Implementação da função para encontrar o valor máximo
}

void freeTree(struct TreeNode* root) {
    // Implementação da função para liberar memória
}
