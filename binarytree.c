#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

int left,right;

// creatring a newnode
struct node *newnode(int data);

//display inorder preorder and postorder
void display_inorder(struct node *root);
void display_preorder(struct node *root);
void display_postorder(struct node *root);


//calculate height
int height_oftree(struct node *root);


int main(){

    struct node *root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(3);

    root->left->left = newnode(4);
    root->left->right = newnode(5);

    root->right->left = newnode(6);
    root->right->right = newnode(7);

    root->left->left->left = newnode(8);
    root->left->left->right = newnode(9);

    root->left->right->left = newnode(10);
    root->left->right->right = newnode(11);

    root->right->left->left = newnode(12);
    root->right->left->right = newnode(13);

    root->right->right->left = newnode(14);
    root->right->right->right = newnode(15);

    display_inorder(root);
    printf("\n");
    display_preorder(root);
    printf("\n");
    display_postorder(root);
    printf("\n");
    printf("%d",height_oftree(root));
}

struct node *newnode(int data){
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = data;

    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void display_inorder(struct node *root){

    if (root == NULL){
        return;
    }

    display_inorder(root->left);

    printf("%d ", root->data);

    display_inorder(root->right);
}

void display_preorder(struct node *root){
    
    if (root == NULL){
        return;
    }

    printf("%d ", root->data);

    display_preorder(root->left);
    display_preorder(root->right);
}

void display_postorder(struct node *root){

    if (root == NULL){
        return;
    }

    display_postorder(root->left);

    display_postorder(root->right);

    printf("%d ", root->data);
}

int height_oftree(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        left=height_oftree(root->left);
        right=height_oftree(root->right);

        if(left > right){
            return left+1;
        }
        else{
            return right+1;
        }
    }
}


