#include<stdio.h>

int main(){
  int a[100],* p;
  int i=0,n;
  p = a;
  printf("Enter the size :");
  scanf("%d",&n);
  printf("Enter the elements:");
  for(i=0;i<n;i++) scanf("%d",(p + i));
  for(i=0;i<n;i++){
    printf("%d %x\n", *(p + i), (p + i));
  }
  return 0;
}
