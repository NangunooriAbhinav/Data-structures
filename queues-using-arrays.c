#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE],front=-1,rear=-1;

void enqueue(int x);
void dequeue();
void display();

void main(){
    int choice,val;
    printf("what do you want to do?\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: printf("enter element:");
                scanf("%d",&val);
                enqueue(val);
                main();
        case 2: dequeue();
                main();
        case 3: display();
                main(); 
        case 4:exit(0);
    } 
}

void enqueue(int x){
    if(rear == SIZE-1){
        printf("queue is full\n");
        main();
    }

    if(front==-1 || front>rear){
        rear=-1;
        front=0;
    }

    rear++;
    queue[rear]=x;
    main();
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("queue is empty\n");
        main();
    }

    front++;
    printf("element is removed\n");
}

void display(){
    int i;
    
    if(front==-1 || front>rear){
        printf("queue is empty\n");
        main();
    }

    printf("queue is:");
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}