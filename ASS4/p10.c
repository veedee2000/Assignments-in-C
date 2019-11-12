#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** adj_matrix;
int n,m;
int visited[100],printed[100];

void dfs(int i,char s[50]){
    visited[i] = 1;
    int j;
    for(j = 1;j <= m;j++){
        if(i == j) continue;
        if(adj_matrix[i][j] && !visited[j]){
            // printf("-> %d ",j);
            char result[50],v[50];
            strcpy(v,s);
            strcat(v," -> ");
            sprintf(result,"%d",j);
            strcat(v,result);
            dfs(j,v);
        }
        else if(visited[j] && !printed[j]) {printf("%s\n",s); printed[j] = 1;}
    }
}

int main(){
    int i,j;
    printf("Enter the maximum number of vertices: ");
    scanf("%d",&m);
    adj_matrix = (int **)(malloc((m + 1) * sizeof(int*)));
    for(i = 0;i <= m;i++){
        adj_matrix[i] = (int *)(malloc((m + 1) * sizeof(int)));
    }
    for(i = 1;i <= m;i++){
        visited[i] = 0;
        printed[i] = 0;
        for(j = 1;j <= m;j++){
            if(i == j) adj_matrix[i][j] = 1;
            else adj_matrix[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        int a,b;
        printf("Enter the edges: ");
        scanf("%d%d",&a,&b);
        adj_matrix[a][b] = 1;
    }
    printf("DFS :- \n");
    for(i = 1;i <= m;i++){
        if(!visited[i]){
            // printf("%d ",i);
            char result[50];
            sprintf(result,"%d",i); 
            dfs(i,result);
        }
    }


    return 0;
}