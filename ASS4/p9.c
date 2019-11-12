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
    int a[15],i,j;
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&a[i]);
    }

    quick_sort(a,0,n);

    int val;
    printf("Enter value to be searched: ");
    scanf("%d",&val);
    if(n == 0) {printf("Not found\n"); return 0;}
    if(n == 1){
        if(a[0] == val) {printf("Found at index: 0\n"); return 0;}
        else {printf("Not found\n"); return 0;}
    } 
    int l = 0,r = n - 1,m;
    while(l < r){
        m = l + (r - l)/2;
        if(l == r - 1){
            if(a[l] == val) {printf("Found at index: %d\n",l); return 0;}
            else if(a[r] == val) {printf("Found at index: %d\n",r); return 0;}
            else {printf("Not found\n"); return 0;}
        }
        else{
            if(a[m] == val) {printf("Found at index: %d\n",m); return 0;}
            else if(a[m] < val) l = m;
            else r = m;
        }
    }
    return 0;
}