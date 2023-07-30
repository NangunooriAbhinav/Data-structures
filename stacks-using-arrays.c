#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void push(int x);
void pop();
void peek();
void display();

int array[SIZE],top=-1;
void main(){
    int choice,val;
    printf("\nwhat do you want to do?\n1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: printf("enter element:");
                scanf("%d",&val);
                push(val);
                main();
        case 2: pop();
                main();
        case 3: display();
                main(); 
        case 4: peek();
                main();
        case 5: exit(0);
    } 
}

void push(int x){
    if(top==SIZE-1){
        printf("stack is full!!");

    }
    else{
        array[++top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("popped element is %d",array[top--]);
    }
}

void peek(){
    printf("top element is %d",array[top]);
}

void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("\n%d",array[i]);
    }
}