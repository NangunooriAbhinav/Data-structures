#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;

int size;

void enqueue(int x);
void dequeue();
void display();
bool isFull(struct node *temp);

int main(){
    int choice,val;

    printf("Enter size of queue:");
    scanf("%d",&size);

    while(true){
        printf("\nwhat do you want to do?\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("enter element:");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break; 
            case 4:exit(0);
        } 
    }
}

void enqueue(int x){

    if(isFull(head)){
        printf("Queue is full!");
    }

    else{
        struct node *new = malloc(sizeof(struct node));
        new->data = x;
        new->next = NULL;

        if(!head){
            head=new;
        }
        else{
            struct node *temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new;
            printf("Element %d is added to the queue successfully",x);
        }
    }
}

void dequeue(){
    if(head==NULL){
        printf("Queue is empty!");    
    }

    else{
        printf("Element removed is %d",head->data);
        head=head->next;
    }
}

void display(){
    if(head==NULL){
        printf("Queue is empty!");    
    }

    else{
        struct node *temp=head;

        printf("Queue is:\n");
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

bool isFull(struct node *temp){
    int x=0;
    while(temp){
        temp=temp->next;
        x++;
    }

    if(x>=size)
        return true;
    else
        return false;    
}