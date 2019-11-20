#include<stdio.h>
#include<stdlib.h>
const int hash = 11;

struct link{
    int mod;
    int val;
    struct link* next;
};

struct link* a[hash];
struct link* create(int, int, struct link*);
int search(int);

int main(){
    int i,n,k;
    for(i = 0;i < hash;i++) a[i] = NULL;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("Enter the value: ");
        scanf("%d",&k);
        a[k%hash] = create(k%hash,k,a[k%hash]);
    }
    int num;
    printf("Enter the number to be searced: ");
    scanf("%d",&num);
    int get = search(num);
    if(get != -1){
        printf("Element found at index %d in value %d link list\n",get,num%hash);
    }
    else printf("Element not present\n");
    return 0;
}

struct link* create(int mod, int val, struct link* head){
    struct link* temp = (struct link*)(malloc(sizeof(struct link)));
    temp -> mod = mod;
    temp -> val = val;
    temp -> next = NULL;
    if(!head) head = temp;
    else{
        struct link* p = head;
        while(p -> next) p = p -> next;
        p -> next = temp;
    }
    return head;
}

int search(int num){
    struct link* temp = a[num%hash];
    int count = 0;
    while(temp){
        if(temp -> val == num) return count;
        else{
            temp = temp -> next;
            ++count;
        }
    }
    return -1;
}