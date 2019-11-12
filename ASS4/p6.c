#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int *l,int n,int *r,int m){
    int i = 0,j = 0,k = 0;
    while(i < n && j < m){
        if(l[i] < r[j])     a[k++] = l[i++];
        else    a[k++] = r[j++];
    }
    while(i < n) a[k++] = l[i++];
    while(j < m) a[k++] = r[j++];
}

void merge_sort(int *a,int n){
    if(n < 2) return;
    int *l,*r,i,mid = n / 2;

    l = (int*)(malloc(sizeof(int) * mid));
    r = (int*)(malloc(sizeof(int) * (n - mid)));

    for(i = 0;i < mid;i++) l[i] = a[i];
    for(i = mid;i < n;i++) r[i - mid] = a[i];

    merge_sort(l,mid);
    merge_sort(r,n - mid);
    merge(a,l,mid,r,n - mid);
    free(l);
    free(r);
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[15],i;
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&a[i]);
    }
    merge_sort(a,n);
    for(i = 0;i < n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}