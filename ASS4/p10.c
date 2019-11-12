#include<stdio.h>
#include<stdlib.h>

struct tree{
    int val;
    struct tree* left;
    struct tree* right;
}

struct tree* create(){
    struct tree* current = q.front();
    q.pop();
    current -> 
}

struct tree* getnode(int val){
    struct tree* node = (struct tree*)(malloc(sizeof(struct tree)));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
}

int main(){
    int n;
    printf("Enter the number of nodes to be inserted: ");
    scanf("%d",&n);
    int i;
    struct tree* root = 
    for(i = 0;i < n;i+=2){

    }

    return 0;
}

