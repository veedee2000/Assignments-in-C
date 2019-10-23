#include<stdio.h>
#include<stdlib.h>

int main(){

    int array[15];
    for(int i=0;i<8;i++){
        printf("Enter number: ");
        scanf("%d",&array[i]);
    }
    for(int i = 0;i < 8;i++){
        for(int j = i + 2;j < 8;j+=2){
            if(i % 2 == 0){
                if(array[i] < array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;  
                }
            } 
            else{
                if(array[i] > array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;  
                }
            }
        }
    }
    printf("Output Array:(Printing two consecutive elements on the same line) \n");
    for(int i=0;i<8;i+=2) printf("%d %d \n",array[i],array[i+1]);

    return 0;
}