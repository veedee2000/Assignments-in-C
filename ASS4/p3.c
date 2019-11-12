#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create(int val){
    struct tree* node = (struct tree*)(malloc(sizeof(struct tree)));
    node -> data = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct tree* insert(struct tree* node, int val){
    if(!node) return create(val);
    else if(node -> data >= val) node -> left = insert(node -> left,val);
    else node -> right = insert(node -> right,val);
    return node;
}

void search(int val){
    
}

void display(struct tree* node){
    struct tree* a[100];
    int front = 0;
    int rear = 0;
    a[0] = node;
    printf("%d\n",node -> data);
    while(front <= rear){
        struct tree* current = a[front];
        front++;
        if(current -> left) {
            printf("%d\n",current -> left -> data);
            a[++rear] = current -> left;
        }
        else printf("NULL\n");

        if(current -> right){
            printf("%d\n",current -> right -> data);
            a[++rear] = current -> right;
        }
        else printf("NULL\n");
    }
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    struct tree* root = NULL;
    while(n--){
        int val;
        printf("Enter the value of the node: ");
        scanf("%d",&val);
        root = insert(root,val);
    }
    display(root);
    int del;
    printf("Enter the value of the node to be deleted: ");
    scanf("%d",&del);
    search(del);

    return 0;
}