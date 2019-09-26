#include<stdio.h>
#include<stdlib.h>

struct link{
  int data;
  struct link* next;
};

struct link* create(struct link* head);
struct link* insertbeg(struct link* head);
void insertend(struct link* head);
struct link* specific(struct link* head);
struct link* delete(struct link* head);
void count(struct link* head);
void display(struct link* head);
void sort(struct link* head);
struct link* reverse(struct link* head);

int main(){
  printf("Enter the initial size: ");
  int n;
  scanf("%d",&n);
  struct link* head = NULL;
  while(n--) head = create(head);
  display(head);
  head = insertbeg(head);
  display(head);
  insertend(head);
  display(head);
  head = specific(head);
  display(head);
  head = delete(head);
  count(head);
  display(head);
  head = reverse(head);
  printf("Reverse link list: \n");
  display(head);
  printf("Sorted linklist: \n");
  sort(head);
  display(head);
  return 0;
}

struct link* create(struct link* head){
  struct link* temp;
  struct link* p;
  temp = (struct link*)malloc(sizeof(struct link));
  temp -> next = NULL;
  printf("Enter value: ");
  scanf("%d",&temp -> data);
  if(head == NULL) head = temp;
  else{
    p = head;
    while(p -> next != NULL) p = p -> next;
    p -> next = temp;
  }
  return head;
}

struct link* insertbeg(struct link* head){
  struct link* temp;
  temp = (struct link*)malloc(sizeof(struct link));
  printf("Enter the value for beginning: ");
  scanf("%d",&temp -> data);
  temp -> next = head;
  head = temp;
  return head;
}

void insertend(struct link* head){
  struct link* temp;
  struct link* p;
  temp = (struct link*)malloc(sizeof(struct link));
  printf("Enter the value for end: ");
  scanf("%d",&temp -> data);
  temp -> next = NULL;
  p = head;
  while(p -> next != NULL){
    p = p -> next;
  }
  p -> next = temp;
}

struct link* specific(struct link* head){
  struct link* temp;
  struct link* p;
  struct link* sub;
  temp = (struct link*)malloc(sizeof(struct link));
  temp -> next = NULL;
  int n;
  printf("Enter the position for node to be added: ");
  scanf("%d",&n);
  printf("Enter the value at position %d: ",n);
  scanf("%d",&temp -> data);
  int i=1;
  p = head;
  while(i < n - 1){
    p = p -> next;
    i++;
  }
  if(n == 1){
    temp -> next = head;
    head = temp;
  }
  else{
    sub = p -> next;
    p -> next = temp;
    temp -> next = sub;
  }
  return head;
}

struct link* delete(struct link* head){
  struct link* temp;
  printf("Enter the node to be deleted: ");
  int n;
  scanf("%d",&n);
  temp = head;
  if(n == 1){
    temp = temp -> next;
    head = temp;
  }
  else{
    n--;
    while(--n){
      temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
  }
  return head;
}

void count(struct link* head){
  int c=0;
  struct link* temp = head;
  while(temp != NULL) {temp = temp -> next; c++;}
  printf("The number of elements = %d\n",c);
}

void display(struct link* head){
  struct link* temp = head;
  while(temp != NULL) {
    printf("%d\n",temp -> data);
    temp = temp -> next;
  }
}

struct link* reverse(struct link* head){
  if(head -> next == NULL) return head;
  struct link* temp = reverse(head -> next);
  head -> next -> next = head;
  head -> next = NULL;
  return temp;
}

// void sort(struct link* head){                           BOTH THE METHODS WORK
//     struct link *i = head, *j = head -> next;
//     int temp;
//     while(i->next != NULL){
//         j = i -> next;
//         while(j != NULL){
//             if(i -> data > j -> data){
//                 temp = i -> data;
//                 i -> data = j -> data;
//                 j -> data = temp;
//             }
//             j = j -> next;
//         }
//         i = i -> next;
//     }
// }

void sort(struct link* head){
    for(struct link* i = head; i -> next != NULL; i = i->next){
        for(struct link* j = i -> next; j != NULL; j = j->next){
            if(i -> data > j -> data){
                int temp  = i -> data;
                i -> data = j -> data;
                j -> data = temp;
            }
        }
    }
}
