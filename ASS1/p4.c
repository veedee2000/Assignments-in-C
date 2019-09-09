#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};

struct node *insertatend(struct node* head);
void traversal(struct node* head);
int main(){
  int i;
  struct node* head;
  head = (struct node*)malloc(sizeof(struct node));
  head = NULL;
  for(i=0;i<10;i++){
    head = insertatend(head);
  }
  traversal(head);
  return 0;
}


struct node *insertatend(struct node *head){
  struct node* temp;
  struct node* p;
  temp = (struct node*)malloc(sizeof(struct node));
  int n;
  printf("Enter the element to be inserted :");
  scanf("%d",&n);
  temp->data = n;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    p = head;
    // printf("%d",p->data);
    while(p->next != NULL){
      p = p->next;
    }
    p -> next = temp;
  }
  return head;
}

void traversal(struct node *head){
  struct node* p;
  p = head;
  while(p -> next != NULL){
    printf("%d\n",p -> data);
    p = p -> next;
  }
  printf("%d\n",p->data);
}
