#include<stdio.h>
#include<stdlib.h>

struct link{
  int data;
  struct link* next;
};

struct link* create(struct link*);


int main(){
  struct link* head;
  head = NULL;
  int n,i;
  printf("Enter even number of values to be inserted: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    head = create(head);
  }
  struct link* head1;
  struct link* p;
  head1 = head;
  i=0;
  while(1){
    ++i;
    if(i == n/2){
      p = head1 -> next;
      head1 -> next = NULL;
      break;
    }
    head1 = head1->next;
  }
  i =0;
  printf("LIST 1      LIST2\n");
  while(i < n/2){
    ++i;
    printf("%d           %d\n",head -> data,p -> data);
    head = head -> next;
    p = p -> next;
  }


  return 0;
}

struct link* create(struct link* head){
  struct link* temp;
  struct link* p;
  temp = (struct link*)malloc(sizeof(struct link));
  printf("Enter the value: ");
  scanf("%d",&temp -> data);
  temp -> next =  NULL;
  if(head == NULL) head = temp;
  else{
    p = head;
    while(p -> next != NULL){
      p = p -> next;
    }
    p -> next = temp;
  }
  return head;
}
