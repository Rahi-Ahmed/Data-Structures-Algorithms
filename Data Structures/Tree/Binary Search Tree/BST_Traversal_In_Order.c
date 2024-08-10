#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* get_new_node(int data){
    struct BstNode* new_node = malloc(sizeof(struct BstNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct BstNode* insert(struct BstNode* root, int data){
    if(root == NULL){
        root = get_new_node(data);
    }else if(data <= root->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(struct BstNode* root, int data){
    if(root == NULL){
        return false;
    }else if(root->data == data){
        return true;
    }else if(root->data >= data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

void print(struct BstNode* root) {
    if (root == NULL) {
        return;
    }

    // Recursively print the left subtree
    print(root->left);

    // Print the root node's data
    printf("%d ", root->data);

    // Recursively print the right subtree
    print(root->right);
}


int main(){
    struct BstNode* root = NULL;
    root  = insert(root, 5);
    root  = insert(root, 3);
    root  = insert(root, 7);
    root  = insert(root, 2);
    root  = insert(root, 4);
    root  = insert(root, 8);
    print(root);
    printf("\n");


    return 0;
}