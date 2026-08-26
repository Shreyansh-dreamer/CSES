#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool ispos=true;

void dfs(int u,int col){
    color[u]=col;

    for(int v:adj[u]){
        if(color[v]==0)
            dfs(v,3-col);
        else if(color[v]==color[u])
            ispos=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    color.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0)
            dfs(i,1);
    }

    if(!ispos){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    for(int i=1;i<=n;i++)
        cout<<color[i]<<" ";

    cout<<"\n";
}