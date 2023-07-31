#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void push(int x);
void pop();
void peek();
void display();

int size,top=-1;

void main(){

    int choice,val;

    printf("Enter size of stack:");
    scanf("%d",&size);

    L1:
    printf("\nWhat do you want to do?\n1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: printf("Enter element:");
                scanf("%d",&val);
                push(val);
                goto L1;
        case 2: pop();
                goto L1;
        case 3: display();
                goto L1; 
        case 4: peek();
                goto L1;
        case 5: exit(0);
    } 

}

void push(int x){

    if(top==size-1){
        printf("stacks is full");
    }
    else{
        struct node *new=malloc(sizeof(struct node));

        new->data=x;
        new->next=head;

        head=new;
        top++;
    }
}

void pop(){
    if(top==-1)
        printf("stack is empty!");
    else{
        printf("popped element is %d\n",head->data);
        head=head->next;
        top--;
    }
}

void display(){
    if(top==-1){
        printf("stack is empty!");
    }
    
    else{
        struct node *temp=head;

        while(temp){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }
}

void peek(){
    if(top==-1)
        printf("stack is empty!");
    else
    printf("top element is %d",head->data);
}