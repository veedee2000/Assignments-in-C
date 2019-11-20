#include<stdio.h>
#include<stdlib.h>

double a[3][14];
int n = 7,m = 7;

struct link{
    double val;
    int row;
    int column;
    struct link* next;
};

struct link* create(struct link*, double, int ,int);

int main(){
    int i,j;
    double matrix[7][7] = {
        {1.1,0,0,0,0,0,0.5},
        {0,1.9,0,0,0,0,0.5},
        {0,0,2.6,0,0,0,0.5},
        {0,0,7.8,0.6,0,0,0},
        {0,0,0,1.5,2.7,0,0},
        {1.6,0,0,0,0.4,0,0},
        {0,0,0,0,0,0.9,1.7}
    };
    int count = 0;
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            if(matrix[i][j] != 0.0){
                a[0][count] = i;
                a[1][count] = j;
                a[2][count] = matrix[i][j];
                ++count;
            }
        }
    }
    printf("Inside array\n");
    for(i = 0;i < 14;i++){
        printf("Row: %d  Column: %d  Value: %f\n",(int)a[0][i],(int)a[1][i],a[2][i]);
    }
    printf("\n\n");
    printf("Linked List\n");
    struct link* head[7];
    for(i = 0;i < n;i++){
        head[i] = NULL;
        for(j = 0;j < m;j++){
            if(matrix[i][j] != 0) head[i] = create(head[i],matrix[i][j],i,j);
        }
    }
    for(i = 0;i < 7;i++){
        struct link* p = head[i];
        while(p){
            printf("Row: %d  Column: %d  Value: %f\n",p -> row,p -> column,p -> val);
            p = p -> next;
        }
    }
    
    return 0;
}

struct link* create(struct link* head, double val,int i,int j){
    struct link* temp = (struct link*)(malloc(sizeof(struct link)));
    temp -> val = val;
    temp -> row = i;
    temp -> column = j;
    temp -> next = NULL;
    if(!head) head = temp;
    else{
        struct link* p = head;
        while(p -> next) p = p -> next;
        p -> next = temp;
    }
    return head;
}