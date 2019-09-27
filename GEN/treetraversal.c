#include<stdio.h>
#include<stdlib.h>

struct tree{

  int data;
  struct tree* left;
  struct tree* right;
    
};

struct tree* create(int data){
    struct tree* t = (struct tree*)malloc(sizeof(struct tree));
    t -> data = data;
    t -> left = NULL;
    t -> right = NULL;
    return t;
}

void pre(struct tree* node){
    if(node == NULL) return;
    printf("%d\n",node -> data);
    pre(node -> left);
    pre(node -> right);
}

void in(struct tree* node){
    if(node == NULL) return;
    in(node -> left);
    printf("%d\n",node -> data);
    in(node -> right);
} 

void post(struct tree* node){
    if(node == NULL) return;
    post(node -> left);
    post(node -> right);
    printf("%d\n",node -> data);
}

int main(){
    
    struct tree* root = create(1);
    root -> left = create(2);
    root -> right = create(3);
    root -> left -> left = create(4);
    root -> left -> right = create(5);
    
    printf("PRE:-\n");
    pre(root);
    printf("IN:-\n");
    in(root);
    printf("POST:-\n");
    post(root);
    
    return 0;
}
