#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char opr);
void pop();
int precedence(char opr);

void main(){

    char exp[100];
    int i=0;

    printf("enter the expression:");
    scanf("%s",exp);

    while(exp[i] != '\0'){
        if(isalnum(exp[i])){
            printf("%c",exp[i]);
        }
        else if(exp[i] == '('){
                push(exp[i]);
            }
        else if(exp[i] == ')'){
                while(stack[top] != '('){
                    pop();
                }
                top--;
            }
        else{
            while(precedence(stack[top]) >= precedence(exp[i])){
                pop();
            }
            push(exp[i]);
        }        
        i++;
    }

    while( top != -1){
        pop();
    }
}

void push(char opr){
    if(top == SIZE-1){
        printf("Stack overflow");   
    }
    else{
        stack[++top]=opr;
    }
}

void pop(){
    if(top == -1){
        printf("stack is empty");
        exit(1);
    }
    else{
        printf("%c",stack[top--]);
    }
}

int precedence(char opr){
    switch(opr){
        case '+':
        case '-':
                 return 1;
                 break;
        case '*':
        case '/':
                 return 2;
                 break;
        case '^':
                return 3;   
        default:
                 return 0;
    }
}