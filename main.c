#include <stdio.h>
#include <malloc.h>

// before using addTail function create a list otherwise you'll get segmentation fault
// which means an access attempt to a memory location that is not allowed to access
struct node{
    int data;
    struct node *link;
};
struct node *head = NULL;
void addTail(int data){
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
void addMiddle(int data, int position){
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
void addHead(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->link = NULL;
    new->link = head;
    head = new;
}

void deleteMiddle(int data){
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


    addHead(12);
    for (int i = 0; i < 1000; ++i) {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        addTail(i); //filo (first in last out
    }
    print();
        return 0;
}
