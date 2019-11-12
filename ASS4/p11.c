#include<stdio.h>
#include<stdlib.h>

int c;

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

void search(struct tree* node, int val){
    if(!node) {c = 0; return;}
    if(node -> data == val) {c = 1; return;}
    else if(node -> data < val) search(node -> right,val);
    else search(node -> left, val);
}

int main(){

    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    struct tree* root = NULL;
    while(n--){
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        root = insert(root,val);
    }
    printf("Enter the value to be searced: ");
    int val;
    scanf("%d",&val);
    search(root, val);
    if(c) printf("Element found\n");
    else printf("Element not found\n");
    return 0;
}