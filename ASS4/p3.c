#include <stdio.h>
#include <stdlib.h>

struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};
typedef struct tree node;

node* create(int x);
node* insert(node* root, int x);
void inorder(node* root);
node* deleteNode(node* root, int x);
node * minValueNode( node* node);
int maxValue(node* node);

int main(void) {
  
  node* root = NULL;
  int choice;
  int val;
  while(1){
    
    printf("\n1-Insert New Node \n2-Delete Node  \n3-Find Max \n4-Find Min \n5-Exit \nEnter the choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:  {
        printf("Enter the val to insert: ");
        scanf("%d", &val);
        root = insert(root, val);
        printf("Inorder traversal after insertion: ");
        inorder(root);
        printf("\n");
        break;
      } 
      case 2:{  
        printf("Enter the node val to delete: ");  
        scanf("%d", &val);
        root = deleteNode(root, val);
        printf("Inorder traversal after deletion: ");
        inorder(root);
        printf("\n");
        break;
      }
      case 3: {
        printf("Max valued node is: %d", maxValue(root));
        break;
      }
      case 4: {
        printf("Min valued node is: %d", (minValueNode(root)->data));
        break;
      }      
      case 5: exit(0);
    }

  } 
   
  return 0;
}

void inorder(node* root){
  if(root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

node* insert(node* root, int x){
  if(root == NULL)
    return create(x);
  if(x < root->data)
    root->left = insert(root->left, x);
  else if(x > root->data)
    root->right = insert(root->right, x);
  return root;
}

node* create(int x){
  node* t = (node*) malloc(sizeof(node));
  t->data = x;
  t->left = NULL;
  t->right = NULL;
  return t;
}

node * minValueNode(node* root) 
{ 
    node* current = root; 
    while (current && current->left != NULL) 
        current = current->left;   
    return current; 
}

int maxValue( node* root) 
{    
    node* current = root; 
    while (current && current->right != NULL)  
        current = current->right;   
    return (current->data); 
} 
  
node* deleteNode(node* root, int key) 
{ 
    if (root == NULL) return root; 
  
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        node* temp = minValueNode(root->right); 
   
        root->data = temp->data; 
  
         
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 