#include<stdio.h>
#include<stdlib.h>

struct link{
  int data;
  struct link* next;
};
struct link* create(struct link* node);

int main(){
  struct link* head1;
  head1 = NULL;
  printf("Enter the number of elements in linked list 1: ");
  int n;
  scanf("%d",&n);
  while(n--){
    head1 = create(head1);
  }
  struct link* head2;
  head2 = NULL;
  printf("Enter the number of elements in linked list 2: ");
  scanf("%d",&n);
  while(n--){
    head2 = create(head2);
  }
  struct link* p1;
  struct link* p2;
  p1 = head1;
  p2 = head2;
  struct link* head3;
  struct link* temp;
  temp = NULL;
  if(p1 -> data < p2 -> data){
    head3 = p1;
    p1 = p1 -> next;
  }
  else{
    head3 = p2;
    p2 = p2 -> next;
  }
  while(p1 != NULL || p2 != NULL){
    if(p2 == NULL || p1 -> data < p2 -> data){
      if(temp == NULL){
        temp = p1;
        head3 -> next = temp;
      }
      else{
        temp -> next = p1;
        temp = p1;
      }
      p1 = p1 -> next;
    }
    else{
      if(temp == NULL){
        temp = p2;
        head3 -> next = temp;
      }
      else{
        temp -> next = p2;
        temp = p2;
      }
      p2 = p2 -> next;
    }
  }

  while(head3 != NULL){
    printf("%d\n", head3 -> data);
    head3 = head3 -> next;
  }

  return 0;
}

struct link* create(struct link* head){
  struct link* p;
  struct link* temp;
  temp = (struct link*)malloc(sizeof(struct link));
  printf("Enter value: ");
  scanf("%d",&temp -> data);
  temp -> next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    p = head;
    while(p -> next != NULL){
      p = p -> next;
    }
    p -> next = temp;
  }
  return head;
}
