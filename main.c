#include <stdio.h>
#include <malloc.h>

// before using addTail function create a list otherwise you'll get segmentation fault
// which means an access attempt to a memory location that is not allowed to access
struct node{
    int data;
    struct node *link;
};
struct node *head = NULL;
void addTail(){
    int data;
    printf("enter any value to insert");
    scanf("%d", &data);
    struct node *iter;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    iter = head;
    while(iter->link != NULL){
        iter = iter->link;
    }

    iter->link = new;
}
void addMiddle(){
    int data,position;
    printf("enter any data and position to insert the data");
    scanf("%d %d", &data,&position);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;

    struct node *iter;
    iter = head;
    for(int i =2; i< position; i++){
        if(iter->link != NULL) { iter = iter->link;}
    }
    new->link = iter->link;
    iter->link = new;
}
void addHead(){
    int data;
    printf("enter any integer");
    scanf("%d", &data);
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    new->link = head;
    head = new;
}

void deleteMiddle(){
    int data;
    printf("enter a vale that you want to delete from the list:");
    scanf("%d", &data);
    struct node *current;
    current = head;

    while(current->link != NULL){
        if(current->link->data == data){
            struct node *delit = current->link;
            current->link = current->link->link;
            free(delit);
            break;
        }
        else {
            current = current->link;
        }
    }
}
void print()  {
    struct node *index = head;
    while(index !=NULL){
        printf("%d\n", index->data);
        index = index->link;
    }
}

int main() {

    int choice;
    while(1){
        printf("\n*******");
        printf("\n0. create");
        printf("\n1. display");
        printf("\n2. insert at the beginning");
        printf("\n3. insert node in specific position");
        printf("\n4. insert node at end of list:");
        printf("\n5. delete a specific node from the list");
        printf("\n6. *** to Exit ***");

          printf("\nenter your choice:");
          scanf("%d", &choice);

        switch (choice) {
            case 0: addHead();
            break;
            case 1: print();
            break;
            case 2: addHead();
            break;
            case 3: addMiddle();
            break;
            case 4: addTail();
            break;
            case 5: deleteMiddle();
            break;
            case 6: exit(0);
            default:
            printf("\nwrong choice");
            break;
        }
    }


    for (int i = 0; i < 1000; ++i) {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        addTail(i); //filo (first in last out
    }
    print();
    return 0;
}
