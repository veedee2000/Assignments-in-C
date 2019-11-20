#include<stdio.h>
const int n = 7;

/* MAX - n^2
   MIN - n
   STABLE
   SORTING IN PLACE
*/

int main(){
    int a[7] = {3,2,1,4,12,42,2};
    int i,j;
    for(i = 0;i < n - 1;i++){
        for(j = 0;j < n - 1 - i;j++){
            if(a[j] > a[j + 1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i = 0;i < n;i++) printf("%d ",a[i]);
    return 0;
}