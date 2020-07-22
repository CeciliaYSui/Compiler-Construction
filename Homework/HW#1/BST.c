//--------------------------------------------------------------------------------------------
// Author ------------- Cecilia Y. Sui
// Course ------------- Compiler Construction 
// Instructor --------- Dr. Crawley 
// Assignment --------- Binary Search Tree Implementation in C 
// Data of Submission - August 27, 2019 
//--------------------------------------------------------------------------------------------

#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>

//--------------------------------------------------------------------------------------------
// Construction of Node 
//--------------------------------------------------------------------------------------------
struct Node {
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 

//--------------------------------------------------------------------------------------------
// function to insert an element into the BST 
//--------------------------------------------------------------------------------------------
struct Node* insert(struct Node* root, int data){
    if (root == NULL){
        root = malloc(sizeof(struct Node)); 
        root->data = data; 
        root->left = root->right = NULL; 
    }
    else if (data < root->data) {
        root->left = insert(root->left, data); 
    }
    else if (data > root->data){
        root->right = insert(root->right, data); 
    }
    return root; 
}; 

//--------------------------------------------------------------------------------------------
// inorder traversal of BST 
//--------------------------------------------------------------------------------------------
void inorder(struct Node* root){
    if (root != NULL){
        inorder(root->left); 
        printf("Content: %d \n", root->data); 
        inorder(root->right); 
    }; 
}; 

//--------------------------------------------------------------------------------------------
// main function 
//--------------------------------------------------------------------------------------------
int main(){
    struct Node* root; 
    int entry; 
    root = NULL; 
    printf("Entry: ");
    scanf("%d", &entry);  
    while (entry != 0){
        root = insert(root, entry); 
        printf("Entry: "); 
        scanf("%d", &entry); 
    }
    printf("\n"); 
    inorder(root); 
    return 0; 
}; 