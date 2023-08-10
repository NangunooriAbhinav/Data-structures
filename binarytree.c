#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct queue{
    struct node *inqueue;
    struct queue *next;
};

struct queue *head = NULL;
struct node *root = NULL;

void display_inorder(struct node *root){

    if (root == NULL){
        return;
    }

    display_inorder(root->left);

    printf("%d", root->data);

    display_inorder(root->right);
}

void display_preorder(struct node *root){
    
    if (root == NULL){
        return;
    }

    printf("%d", root->data);

    display_preorder(root->left);
    display_preorder(root->right);
}

void display_postorder(struct node *root){

    if (root == NULL){
        return;
    }

    display_postorder(root->left);

    display_postorder(root->right);

    printf("%d", root->data);
}

void enqueue(struct node *root){

    struct queue *new = malloc(sizeof(struct queue));

    new->inqueue = root;

    new->next = NULL;

    if(!head){
        head=new;
    }
    
    else{
        struct queue *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }

}

void dequeue(){
    head=head->next;
}

void display_levelorder(struct node *temp){

    int i=1,branchno=0;

    enqueue(temp);
    
    while(temp){

        printf("%d ",temp->data);
        
        if(i == pow(2,branchno)){
            printf("\n");
            branchno++;
            i=0;
        }

        i++;

        if(temp->left != NULL){
            enqueue(temp->left);
        }

        if(temp->right != NULL){
            enqueue(temp->right);
        }

        dequeue();

        temp=head->inqueue;
    }
}
struct node *newnode(int data){
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = data;

    newnode->left = NULL;
    newnode->right = NULL;
}

void main(){

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
    display_levelorder(root);
}