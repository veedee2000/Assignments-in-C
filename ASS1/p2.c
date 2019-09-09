#include<stdio.h>
#include<string.h>
struct student{
  int roll;
  char name[20];
  float percent;
};
struct student a[200];
int size = 0;

void add();
void display();
void search();
void modify();

int main(){
  int k;
  while(1){
    printf("1: add\n2: display\n3: search\n4: modify\n5: exit\n");
    scanf("%d",&k);
    if(k == 5) break;
    switch(k){
      case 1: {add(); break;}
      case 2: {display(); break;}
      case 3: {search(); break;}
      case 4: {modify(); break;}
    }
  }

  return 0;
}

void add(){
  int r;
  char n[50];
  float p;
  printf("Enter the roll :");
  scanf("%d",&r);
  a[size].roll = r;
  printf("Enter the name :");
  scanf("%s",n);
  strcpy(a[size].name ,n);
  printf("Enter the percent :");
  scanf("%f",&p);
  a[size].percent = p;
  ++size;
}

void display(){
  int i=0;
  for(i=0;i<size;i++){
    printf("Roll = %d\n",a[i].roll);
    printf("Name = %s\n",a[i].name);
    printf("Percent = %f\n",a[i].percent);
    printf("-----------------------\n");
  }
}
void search(){
  char name[50];
  int i=0;
  printf("Enter the name to search :");
  scanf("%s",name);
  int b = 0;
  for(i=0;i<size;i++){
    if(strcmp(name,a[i].name) == 0){
      b = 1;
      printf("Roll = %d\n",a[i].roll);
      printf("Name = %s\n",a[i].name);
      printf("Percent = %f\n",a[i].percent);
      printf("-----------------------\n");
    }
  }
  if(!b) printf("RECORD DOES NOT EXIST\n");
}

void modify(){
  int r,i=0;
  float p;
  printf("Enter the roll no. :");
  scanf("%d",&r);
  printf("Enter the modified percent :");
  scanf("%f",&p);
  for(i=0;i<size;i++){
    if(a[i].roll == r){
      a[i].percent = p;
    }
  }
}
