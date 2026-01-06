#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100

// 1. Structure Definition
typedef struct node {
   char *key;          // The string element used for comparison and storage
   struct node* LC;   // Left Child pointer
   struct node* RC;   // Right Child pointer
} Node, *BST;

void insert(BST *tree, const char *key_data){
    if(*tree == NULL){
        Node *newNode = calloc(1, sizeof(Node));
        newNode->key = malloc(MAX_KEY_LEN);
        strcpy(newNode->key, key_data);
        newNode->LC = NULL;
        newNode->RC = NULL;
    }

    if(strcmp(key_data, (*tree)->key) == 0){
        printf("Key already exists");
        return;
    }
    if(strcmp(key_data, (*tree)->key) > 0){
        insert(&(*tree)->LC, key_data);
    }

    if(strcmp(key_data, (*tree)->key) < 0){
        insert(&(*tree)->RC, key_data);
    }
}

BST delete(BST tree, const char *key_data){

    if(strcmp(key_data, tree->key) > 0){
        tree->RC = delete(tree->RC, key_data);
    } else if(strcmp(key_data, tree->key) < 0){
        tree->LC = delete(tree->LC, key_data);
    } else {

        //one child
        if(tree->LC == NULL){
            BST RightChild = tree->RC;
            free(tree);
            return RightChild;
        }
    
        if(tree->RC == NULL){
            BST LeftChild = tree->RC;
            free(tree);
            return LeftChild;
        }

        //two children
        BST succ = tree->RC;
        while(succ->LC != NULL) succ = succ->LC;

        strcpy(tree->key, succ->key);
        tree->RC = deleteNode(tree->RC, succ->key);

    }
}

void inorderTraversal(BST tree) {
    if(tree == NULL){
        return;
    }
    
    inorderTraversal(tree->LC);
    printf("\"%s\" ", tree->key);
    inorderTraversal(tree->RC);
}

void preorderTraversal(BST tree) {
    // TODO...
    if(tree == NULL){
        return;
    }
    
    printf("\"%s\" ", tree->key);
    preorderTraversal(tree->LC);
    preorderTraversal(tree->RC);
}

void postorderTraversal(BST tree) {
    // TODO...
    if(tree == NULL){
        return;
    }
    
    postorderTraversal(tree->LC);
    postorderTraversal(tree->RC);
    printf("\"%s\" ", tree->key);
}

void destroyTree(BST tree) {
    if (tree != NULL) {
        destroyTree(tree->LC);
        destroyTree(tree->RC);

        if (tree->key != NULL) {
            free(tree->key);
        }

        free(tree);
    }
}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Initializing and Inserting String Data into BST ---\n");

    // Root: 'Mango'
    // Left: 'Apple', 'Banana'
    // Right: 'Pineapple', 'Grape', 'Orange', 'Kiwi'
    insert(&myTree, "Mango");
    insert(&myTree, "Apple");
    insert(&myTree, "Pineapple");
    insert(&myTree, "Banana");
    insert(&myTree, "Grape");
    insert(&myTree, "Orange");
    insert(&myTree, "Kiwi");

    // Test duplicate handling
    insert(&myTree, "Mango");

    printf("\n\n--- BST Traversal Results ---\n");

    // In-Order: Sorted (A, B, G, K, M, O, P)
    printf("1. In-Order Traversal (Left-Root-Right, Sorted):\n");
    printf("   ");
    inorderTraversal(myTree);
    printf("\n\n");

    // Pre-Order: Root first (M, A, B, P, G, K, O)
    printf("2. Pre-Order Traversal (Root-Left-Right):\n");
    printf("   ");
    preorderTraversal(myTree);
    printf("\n\n");

    // Post-Order: Root last (B, A, K, O, G, P, M)
    printf("3. Post-Order Traversal (Left-Right-Root):\n");
    printf("   ");
    postorderTraversal(myTree);
    printf("\n\n");

    // 3. Clean up memory
    destroyTree(myTree);
    printf("Tree destroyed and memory freed.\n");

    return 0;
}

void insert(BST *tree, const char *key_data){

}