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
    BST *temp = tree;

    while(*temp != NULL && strcmp((*temp)->key, key_data) != 0){
        temp = (strcmp((*temp)->key, key_data) > 0) ? &(*temp)->RC : &(*temp)->LC;
    }

    if(*temp == NULL){
        *temp = (BST)calloc(1, sizeof(Node));
        strcpy((*temp)->key, key_data);
    }
}

BST delete(BST tree, const char *key_data){
    BST temp = tree;
    while(temp != NULL &&  strcmp(temp->key, key_data) != 0){
        temp = (strcmp(temp->key, key_data) > 0) ? &temp->RC : &temp->LC;
    }

    if(temp == NULL) return;

    if(strcmp(temp->key, key_data) == 0){

        if(temp->LC == NULL){
            BST RightChild = temp->RC;
            free(temp);
            return RightChild;
        } else if (temp->RC == NULL){
            BST LeftChild = temp->LC;
            free(temp);
            return LeftChild;
            }   
    }
    
}

void preorderTraversal(BST tree){
    if (tree == NULL) return;

    BST stack[100];
    int top = -1;

    stack[++top] = tree;

    while(top >= 0) {
        BST node = stack[top--];
        printf("%s", node->key);

        if(node->RC) stack[++top] = node->RC;
        if(node->LC) stack[++top] = node->LC;
    }

}