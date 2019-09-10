#include<stdio.h>
#include<stdlib.h>

struct stack{
  char data;
  struct stack* next;
};

struct stack* create(struct stack* head,char s);

int main(){
  struct stack* head;
  head = NULL;
  printf("Enter the string: ");
  char s[100];
  fgets(s,100,stdin);
  int i=0;
  while(s[i]!='\0'){
    head = create(head,s[i]);
    ++i;
  }
  printf("Reverse string: ");
  while(head != NULL){
    printf("%c",head -> data);
    head = head -> next;
  }
  printf("\n");
  return 0;
}

struct stack* create(struct stack* head,char s){
  struct stack* temp;
  struct stack* p;
  temp = (struct stack*)malloc(sizeof(struct stack));
  temp -> data = s;
  if(head == NULL){
    head = temp;
    head -> next = NULL;
  }
  else{
    temp -> next = head;
    head = temp;
  }
  return head;
}
