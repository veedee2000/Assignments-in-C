/*
    n = 6
    Enter the value: 2
    Enter the value: 42
    Enter the value: 43
    Enter the value: 2
    Enter the value: 15
    Enter the value: 532
*/

#include<stdio.h>

int b[15];

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
        if(a[i] < pivot){
            swap(&a[i],&a[pi]);
            swap(&b[i],&b[pi]);
            pi++;
        }
    }
    swap(&a[pi],&a[end]);
    swap(&b[pi],&b[end]);
    return pi;
}

void quick_sort(int *a,int start,int end){
    if(start < end){
        int pi = partition(a,start,end);
        quick_sort(a,start,pi - 1);
        quick_sort(a,pi + 1,end);
    }
}

int is_stable(int a[],int n){
    int i,j;
    for(i = 0;i < n;i++){
        for(j = i + 1;j < n;j++){
            if(a[i] == a[j] && b[i] > b[j]) return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int a[15],i;
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&a[i]);
        b[i] = i;
    }
    quick_sort(a,0,n - 1);
    for(i = 0;i < n;i++) printf("%d %d\n",a[i],b[i]);
    printf("\n");
    if(is_stable(a,n)) printf("Stable\n");
    else printf("Not Stable\n");
    return 0;
}