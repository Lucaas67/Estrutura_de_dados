#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    struct TreeNode* root = NULL;
    
    // Inserir valores na ABB
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Testar as operações
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));

    int key_to_find = 30;
    if (search(root, key_to_find)) {
        printf("%d found in the tree.\n", key_to_find);
    } else {
        printf("%d not found in the tree.\n", key_to_find);
    }

    key_to_find = 90;
    if (search(root, key_to_find)) {
        printf("%d found in the tree.\n", key_to_find);
    } else {
        printf("%d not found in the tree.\n", key_to_find);
    }

    // Remover um valor da ABB
    int key_to_delete = 30;
    root = deleteNode(root, key_to_delete);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    // Liberar memória
    freeTree(root);

    return 0;
}
