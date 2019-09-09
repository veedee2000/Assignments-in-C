#include <stdio.h>
#include <stdlib.h>

struct stack{
  int data;
  struct stack* next;
};

struct queue{
  int data;
  struct queue* next;
};

struct stack* createstack(struct stack* heads);
struct stack* deletestack(struct stack* heads);
void displaystack(struct stack* heads);

struct queue* createqueue(struct queue* top,struct queue* rear);
struct queue* deletequeue(struct queue* rear);
void displayqueue(struct queue* rear);

int main() {
  struct stack* heads;
  heads = (struct stack*)malloc(sizeof(struct stack));
  heads -> next = NULL;
  heads -> data = -1;
  int n;
  printf("Enter the number of elements in stack: ");
  scanf("%d",&n);
  while(n--){
    heads = createstack(heads);
  }
  heads = deletestack(heads);
  displaystack(heads);

  struct queue* top;
  top = (struct queue*)malloc(sizeof(struct queue));
  top -> data = -1;
  struct queue* rear;
  rear = (struct queue*)malloc(sizeof(struct queue));
  rear -> data = -1;
  printf("Enter the number of elements in queue: ");
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    if(i==0){
      top = createqueue(top,rear);
      rear = top;
    }
    else if(i==1){
      top = createqueue(top,rear);
      rear -> next = top;
    }
    else top = createqueue(top,rear);
  }
  rear = deletequeue(rear);
  displayqueue(rear);
  return 0;
}

struct stack* createstack(struct stack* heads){
  struct stack* temp;
  temp = (struct stack*)malloc(sizeof(struct stack));
  temp -> next = NULL;
  printf("Enter the value in stack: ");
  int k;
  scanf("%d",&k);
  temp -> data = k;
  if(heads -> data == -1){
    heads = temp;
  }
  else{
    temp -> next =  heads;
    heads = temp;
  }
  return heads;
}

struct stack* deletestack(struct stack* heads){
  struct stack* temp;
  printf("The element deleted is: %d \n",heads -> data);
  temp = heads -> next;
  heads = temp;
  return heads;
}

void displaystack(struct stack* heads){
  struct stack* p;
  p = heads;
  printf("The elements are:\n");
  while(p -> next != NULL){
    printf("%d\n",p -> data);
    p = p -> next;
  }
  printf("%d\n",p -> data);
}

struct queue* createqueue(struct queue* top, struct queue* rear){
  struct queue* temp;
  temp = (struct queue*)malloc(sizeof(struct queue));
  printf("Enter the element: ");
  scanf("%d",&temp -> data);
  temp -> next = NULL;
  if(rear -> data == -1){
    rear = temp;
    top = temp;
  }
  else if(rear -> next == NULL){
    top -> next = temp;
    top = temp;
    rear -> next = temp;
  }
  else{
    top -> next = temp;
    top = temp;
  }
  return top;
}

struct queue* deletequeue(struct queue* rear){
  struct queue* temp;
  printf("The deleted element is %d\n",rear -> data);
  temp = rear -> next;
  rear = temp;
  return rear;
}

void displayqueue(struct queue* rear){
  struct queue* temp;
  printf("The elements in the queue are:\n");
  while(temp -> next != NULL){
    printf("%d\n",temp -> data);
    temp = temp -> next;
  }
  printf("%d\n",temp-> data);
}
