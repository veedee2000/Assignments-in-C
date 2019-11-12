#include<stdio.h>
#include<stdlib.h>

int** adj_matrix;
int n,m;
int visited[100];

void dfs(int i){
    visited[i] = 1;
    int j;
    for(j = 1;j <= m;j++){
        if(i == j) continue;
        if(adj_matrix[i][j] && !visited[j]){
            printf("-> %d ",j);
            dfs(j);
        }
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
            printf("%d ",i);
            dfs(i);
            printf("\n");
        }
    }


    return 0;
}