#include<stdio.h>

int main(){
  int i=0,a[15];
  for(i=0;i<15;i++){
    a[i] = i;
  }
  printf("Element insert:");
  int n;
  scanf("%d",&n);
  int temp = a[6],temp1;
  a[6] = n;
  for(i=7;i<15;i++){
    temp1 = a[i];
    a[i] = temp;
    temp = temp1;
  }
  for(i=0;i<15;i++) printf("%d ",a[i]);
  for(i=6;i<15;i++){
    a[i] = a[i+1];
  }
  printf("\n");
  for(i=0;i<14;i++) printf("%d ",a[i]);
  return 0;
}
