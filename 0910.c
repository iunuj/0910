#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

void GenerateArrayTree(int* tree) {
    int list[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    for (int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }

    for (int i = 0; i < 15; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

void ArrayPreOrder(int* tree, int index, int size) {
    if (index >= size) return;
    printf("%d ", tree[index]);
    ArrayPreOrder(tree, 2 * index + 1, size);
    ArrayPreOrder(tree, 2 * index + 2, size); 
}

void ArrayInOrder(int* tree, int index, int size) {
    if (index >= size) return;
    ArrayInOrder(tree, 2 * index + 1, size); 
    printf("%d ", tree[index]);
    ArrayInOrder(tree, 2 * index + 2, size); 
}

void ArrayPostOrder(int* tree, int index, int size) {
    if (index >= size) return;
    ArrayPostOrder(tree, 2 * index + 1, size);
    ArrayPostOrder(tree, 2 * index + 2, size); 
    printf("%d ", tree[index])
}

void ArrayOrders(int* tree, int size) {
    printf("어레이 트리 전위 순회: ");
    ArrayPreOrder(tree, 0, size);
    printf("\n어레이 트리 중위 순회: ");
    ArrayInOrder(tree, 0, size);
    printf("\n어레이 트리 후위 순회: ");
    ArrayPostOrder(tree, 0, size);
    printf("\n");
}

TreeNode* BuildTreeFromArray(int* arr, int index, int size) {
    if (index >= size) return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = arr[index];
    node->left = BuildTreeFromArray(arr, 2 * index + 1, size);
    node->right = BuildTreeFromArray(arr, 2 * index + 2, size);
    return node;
}

void LinkPreOrder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data); 
    LinkPreOrder(node->left); 
    LinkPreOrder(node->right); 
}

void LinkInOrder(TreeNode* node) {
    if (node == NULL) return;
    LinkInOrder(node->left); 
    printf("%d ", node->data); 
    LinkInOrder(node->right); 
}

void LinkPostOrder(TreeNode* node) {
    if (node == NULL) return;
    LinkPostOrder(node->left);
    LinkPostOrder(node->right); 
    printf("%d ", node->data);
}

void LinkOrders(TreeNode* root) {
    printf("링크 트리 전위 순회: ");
    LinkPreOrder(root);
    printf("\n링크 트리 중위 순회: ");
    LinkInOrder(root);
    printf("\n링크 트리 후위 순회: ");
    LinkPostOrder(root);
    printf("\n");
}

void FreeTree(TreeNode* node) {
    if (node == NULL) return;
    FreeTree(node->left);
    FreeTree(node->right);
    free(node);
}

int main() {
    int arr[15];
    GenerateArrayTree(arr);
    ArrayOrders(arr, 15);
    TreeNode* root = BuildTreeFromArray(arr, 0, 15);
    LinkOrders(root);
    FreeTree(root);

    return 0;
}