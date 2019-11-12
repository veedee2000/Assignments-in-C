#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int i = 0;
    int a[15];
    for(i = 0;i < n;i++){
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    for(int i = 1;i < n;i++){
        int value = a[i];
        int hole = i;
        while(hole > 0 && a[hole - 1] > value){
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
    }
    for(int i = 0;i < n;i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}