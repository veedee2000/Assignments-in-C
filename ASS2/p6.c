#include<stdio.h>
#include<stdlib.h>

struct link{
  int data;
  struct link* pre;
  struct link* next;
};

struct link* create(struct link* head);
void display(struct link* head);
struct link* specific(struct link* head);
struct link* delete(struct link* head);
void count(struct link* head);
struct link* reverse(struct link* head);
void traverse(struct link* head);

int main(){
  struct link* head = NULL;
  printf("Enter initial size of doubly link list: ");
  int n;
  scanf("%d",&n);
  while(n--) head = create(head);
  display(head);
  head = specific(head);
  display(head);
  head = delete(head);
  display(head);
  count(head);
  head = reverse(head);
  display(head);
  traverse(head);
  return 0;
}

struct link* create(struct link* head){
  struct link* temp = (struct link*)malloc(sizeof(struct link));
  struct link* p;
  printf("Enter the value: ");
  scanf("%d",&temp -> data);
  temp -> next = NULL;
  temp -> pre = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    p = head;
    while(p -> next != NULL){
      p = p-> next;
    }
    p -> next = temp;
    temp -> pre = p;
  }
  return head;
}

struct link* specific(struct link* head){
  struct link* temp = (struct link*)malloc(sizeof(struct link));
  struct link* p;
  printf("Enter the position to insert new node: ");
  int n;
  scanf("%d",&n);
  printf("Enter the value to be inserted: ");
  scanf("%d",&temp -> data);
  if(n == 1){
    temp -> next = head;
    head -> pre = temp;
    head = temp;
  }
  else{
    struct link* sub;
    p = head;
    --n;
    while(--n){
      p = p -> next;
    }
    sub = p -> next;
    p -> next = temp;
    temp -> pre = p;
    temp -> next = sub;
    sub -> pre = temp;
  }
  return head;
}

struct link* delete(struct link* head){
  struct link* p;
  printf("Enter the node to be deleted: ");
  int n;
  scanf("%d",&n);
  if(n == 1){
    head = head -> next;
    head -> pre = NULL;
  }
  else{
    p = head;
    --n;
    while(--n){
      p = p -> next;
    }
    p -> next = p -> next -> next;
    if(p -> next != NULL) p -> next -> pre = p;
  }
  return head;
}

void count(struct link* head){
  struct link* p;
  p = head;
  int c=0;
  while(p != NULL){
    p = p -> next;
    c++;
  }
  printf("The count is: %d\n",c);
}

struct link* reverse(struct link* head){
  if (!head) return NULL;
  struct link* temp = head -> next;
  head -> next = head -> pre;
  head -> pre = temp;
  if (!head -> pre) return head;
  return reverse(head ->pre);
}

void traverse(struct link* head){
  struct link* p = head;
  while(p -> next != NULL){
    p = p -> next;
  }
  printf("Traversing backwards:\n");
  while(p != NULL){
    printf("%d\n",p -> data);
    p = p -> pre;
  }
}

void display(struct link* head){
  struct link* p;
  p = head;
  printf("The doubly link list:\n");
  while(p != NULL){
    printf("%d\n",p->data);
    p = p -> next;
  }
}
