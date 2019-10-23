#include<stdio.h>
#include<stdlib.h>

struct link{
    int data;
    struct link* next;
};

struct link* create(struct link*,int);
void display(struct link*);

int main(){

    struct link* head = NULL;
    for(int i=1;i<10;i++){
        head = create(head,i);
    }
    printf("The initial list: \n");
    display(head);
    struct link* p = head, *head1 = NULL, *head2 = NULL;
    while(p != NULL){
        if((p -> data) % 2 == 0) head1 = create(head1, p -> data);
        else head2 = create(head2, p -> data);
        p = p -> next;
    }
    printf("Odd-list \n");
    display(head1);
    printf("Even-list \n");
    display(head2);


    return 0;
}

struct link* create(struct link* head,int data){
    struct link* temp = (struct link*)(malloc(sizeof(struct link)));
    temp -> next = NULL;
    temp -> data = data;
    if(!head) head = temp;
    else{
        struct link* p = head;
        while(p -> next != NULL) p = p -> next;
        p -> next = temp;
    }
    return head;
}

void display(struct link* head){
    struct link* p = head;
    while(p != NULL){
        printf("%d \n",p -> data);
        p = p -> next;
    }
}