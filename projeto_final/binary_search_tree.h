#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insert(struct TreeNode* root, int key);
struct TreeNode* deleteNode(struct TreeNode* root, int key);
int search(struct TreeNode* root, int key);
void inorder(struct TreeNode* root);
void preorder(struct TreeNode* root);
void postorder(struct TreeNode* root);
int findMin(struct TreeNode* root);
int findMax(struct TreeNode* root);
void freeTree(struct TreeNode* root);

#endif
