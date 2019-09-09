#include<stdio.h>
#include<stdlib.h>

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};

struct tree* insert(struct tree* node,int key);
struct tree* createnode(int key);
void display(struct tree* root);

int main(){
  int n;
  printf("Enter the number of elements in tree: ");
  scanf("%d",&n);
  struct tree* root;
  root = NULL;
  while(n--){
    int k;
    printf("Enter the new node: ");
    scanf("%d",&k);
    root = insert(root,k);
  }
  display(root);
  return 0;
}

struct tree* insert(struct tree* node,int key){
  struct tree* p;
  if(node == NULL){
    return createnode(key);
  }
  else if(node -> data >= key) node -> left = insert(node -> left,key);
  else node -> right = insert(node -> right, key);
  return node;
}
struct tree* createnode(int key){
  struct tree* p;
  p = (struct tree*)malloc(sizeof(struct tree));
  p -> data = key;
  p -> left = NULL;
  p -> right = NULL;
  return p;
}

void display(struct tree* root){
  if(root != NULL){
    display(root -> left);
    printf("%d\n",root -> data);
    display(root -> right);
  }
}
