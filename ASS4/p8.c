#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int a[15],i,j;
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&a[i]);
    }
    for(i = 0;i < n;i++){
        int min = a[i],minin = i;
        for(j = i;j < n;j++){
            if(a[j] < min){
                min = a[j];
                minin = j;
            }
        }
        swap(&a[i],&a[minin]);
    }
    for(i = 0;i < n;i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}