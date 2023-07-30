#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void menu();
void insertAtStart(int x);
void insertAtEnd(int x);
void insertAfter_nthNode(int n, int x);
void deleteAtStart();
void deleteAtEnd();
void deleteAfter_nthNode(int n);
void findElement(int x);
void sortList();
int size(struct node *temp);
void reverse(struct node *temp);
void display();

int main() {
   int choice=1, i=0, d=0, data, pos;

   while(choice){
      menu();

      scanf("%d", &choice);


      switch (choice) {

         case 1:

            display();

            break;
      
         case 2:
         //INSERTION

            printf("\nChoose one option - \n\n\t1. Insert at first\n\t2. Insert at end\n\t3. Insert at any other position\n\nEnter[1-3]: ");
            scanf("%d", &i);

            switch (i){
               case 1:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at beginning . . .\n\nDone!", data);
                  insertAtStart(data);
                  display();
                  break;

               case 2:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at end . . .\n\nDone!", data);
                  insertAtEnd(data);
                  display();
                  break;

               case 3:
                  printf("\nEnter element: ");
                  scanf("%d", &data);
                  printf("\nEnter position: ");
                  scanf("%d", &pos);
                  printf("\nBefore insertion - ");
                  display();
                  printf("\n\nInserting %d at position %d . . .\n\nDone!", data, pos);
                  insertAfter_nthNode(pos,data);
                  display();
                  break;
            }


            break;
      
         case 3:
         // DELETION

            printf("\nChoose one option - \n\n\t1. Delete element at front\n\t2. Delete element at end\n\t3. Delete at any other position\n\nEnter[1-3]: ");
            scanf("%d", &d);

            switch (d){
               case 1:
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting first element . . .\n\nDone!");
                  deleteAtStart();
                  break;

               case 2:
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting last element . . .\n\nDone!", data);
                  deleteAtEnd();
                  break;

               case 3:
                  printf("\nEnter position: ");
                  scanf("%d", &pos);
                  printf("\nBefore deletion - ");
                  display();
                  printf("\n\nDeleting at position %d...\n\nDone!", pos);
                  deleteAfter_nthNode(pos);
                  break;
            }

            break;

    
         case 4:
         //SEARCH

            printf("\n\nEnter element to be searched: ");
            scanf("%d", &data);

            findElement(data);

            break;
      
         case 5:
         //REVERSE

            reverse(head);
            printf("\n\nReversing list . . .\n\nDone!");
            display();

            break;
      
         case 6:
         //SORTING
            sortList();
            printf("\n\nSorting list . . .\n\nDone!");
            display();

            break;
      
         case 7:
            choice=0;
            break;
      
         default:
            printf("\n\nEnter valid choice!");
      }
   }
}

void insertAtStart(int x) {
    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = head;

    head = new;
}

void insertAtEnd(int x) {
    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    struct node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void insertAfter_nthNode(int n, int x) {
    n--;
    struct node *temp = head;

    for(int i=0; i<n; i++) {
        temp = temp->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = temp->next;
    temp->next = new;
}

void deleteAtStart() {
    head = head->next;
}

void deleteAtEnd() {
    if(head == NULL) {
        printf("List empty.\n");
        exit(0);
    }
    struct node *temp = head->next;
    struct node *prev = head;

    while(temp->next != NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;
}

void deleteAfter_nthNode(int n) {
    n--;
    struct node *temp = head->next;
    struct node *prev = head;

    for(int i=0; i<n; i++) {
        temp = temp->next;
        prev = prev->next;
    }

    prev->next = temp->next;
}

void display() {
    struct node *temp = head;

    while(temp) {
        printf("\n%d ", temp->data);
        temp = temp->next;
    }
}

void findElement(int x){
    int i=0,status=0;
    struct node *temp=head;
    
    while(temp){
        ++i;
        if(temp->data==x){
            printf("element %d found at %d node",temp->data,i);
            status=1;
            break;
        }
        temp=temp->next;
    }
    if(status==0){
        printf("element not found");
    }
}

void sortList(){
    int n=size(head);
    int tempdata;
    struct node *prev=head;
    struct node *forward=head->next;

    for(int i=0;i<n;i++){
        prev=head;
        forward=head->next;
        for(int j=0;j<n-i-1;j++){
            if(prev->data > forward->data){
                tempdata=forward->data;
                forward->data=prev->data;
                prev->data=tempdata;
            }
            prev=prev->next;
            forward=forward->next;
        }
    }
}

void reverse(struct node *temp){

    if(temp->next == NULL){
        head=temp;
        return;
    }
    else{
    reverse(temp->next);
    }
    insertAtEnd(temp->data);
}

int size(struct node *temp){
    int size=0;

    while(temp){
        size++;
        temp=temp->next;
    }

    return size;
}
void menu(){

   printf("\n\n____________________________________________________________");
   printf("\n\nChoose one - ");
   printf("\n\n\n\t1. DISPLAY the list");
   printf("\n\n\t2. INSERTING a node into the list");
   printf("\n\n\t3. DELETING a node from the list");
   printf("\n\n\t4. SEARCHING for an element in the list");
   printf("\n\n\t5. REVERSING the list");
   printf("\n\n\t6. SORTING the list");
   printf("\n\n\t7. EXIT");

   printf("\n\nEnter the operation you'd like to perform [1-8] : ");
}
