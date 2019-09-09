#include<stdio.h>
#include<stdlib.h>

struct node{
  int expo;
  int data;
  struct node* next;
};

struct node* create(struct node* head,int expo,int data);
void traverse(struct node* head, int expo, int data, int chech);
void display(struct node* head);

int main(){
  struct node* head;
  head = NULL;
  int n = -1;
  while(++n < 20){
    head = create(head,n,0);
  }
  int i=0;
  char p1[100],p2[100];
  printf("Enter polynomial 1: ");
  fgets(p1,100,stdin);
  for(i=0;p1[i]!='\0';i++){
    if(p1[i] == '^'){
      traverse(head,(p1[i+1] - '0'),(p1[i-2] - '0'),(p1[i-4] == '+'));
    }
  }
  printf("Enter polynomial 2: ");
  fgets(p2,100,stdin);
  for(i=0;p2[i]!='\0';i++){
    if(p2[i] == '^'){
      traverse(head,(p2[i+1] - '0'),(p2[i-2] - '0'),(p2[i-4] == '+'));
    }
  }
  display(head);
  if(head -> next == NULL) printf("rf");
  return 0;
}


struct node* create(struct node* head,int expo,int data){
  struct node* temp;
  struct node* p;
  temp = (struct node*)malloc(sizeof(struct node));
  temp -> expo = expo;
  temp -> data = data;
  temp -> next = NULL;
  if(head ==  NULL) head = temp;
  else{
    p = head;
    while(p -> next != NULL){
      p = p -> next;
    }
    p -> next = temp;
  }
  return head;
}

void traverse(struct node* head,int expo, int data, int check){
  struct node* p;
  p = head;
  while(p -> next != NULL){
    if(p -> expo == expo){
      if(check) p -> data += data;
      else p -> data -= data;
    }
    p = p -> next;
  }
}

void display(struct node* head){
  struct node* p;
  p = head;
  while(p -> next != NULL){
    if(p -> data != 0){
      if(p -> data < 0) printf("%dx^%d ",p -> data,p -> expo);
      else printf("+%dx^%d ",p -> data,p -> expo);
    }
    p = p -> next;
  }
  if(p -> data != 0){
    if(p -> data < 0) printf("%dx^%d ",p -> data,p -> expo);
    else printf("+%dx^%d ",p -> data,p -> expo);
  }
}
