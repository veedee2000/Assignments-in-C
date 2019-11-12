#include<stdio.h>

void swap(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a,int start,int end){
    int pivot = a[end];
    int pi = start,i;
    for(i = start;i < end;i++){
        if(a[i] <= pivot){
            swap(&a[i],&a[pi]);
            pi++;
        }
    }
    swap(&a[pi],&a[end]);
    return pi;
}

void quick_sort(int *a,int start,int end){
    if(start < end){
        int pi = partition(a,start,end);
        quick_sort(a,start,pi - 1);
        quick_sort(a,pi + 1,end);
    }
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int a[15],i;
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n);
    for(i = 0;i < n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}