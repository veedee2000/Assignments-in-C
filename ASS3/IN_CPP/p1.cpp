#include<bits/stdc++.h>

using namespace std;

int ans=0,b[100];
vector<int>v[100];
void dfs(int i){
    b[i] = 1;
    if(v[i].size() == 0) ++ans;
    for(int j=0;j<v[i].size();j++){
        if(b[v[i][j]]){
            dfs(v[i][j]);
        }
    }
}

int main(){
    int n,x,y,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=0;i<100;i++) b[i] = 0;
    for(int i=1;i<=m;i++){
        dfs(i);
    }
    cout<<ans;
    return 0;
}
