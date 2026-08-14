#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<long long>sub,ans;
long long total=0;
int n;

int dfs1(int u,int par){
    if(adj[u].size()==1 && adj[u][0]==par)
        return sub[u]=1;

    int ans=1;

    for(auto v:adj[u]){
        if(v==par)continue;

        ans+=dfs1(v,u);
    }

    return sub[u]=ans;
}

void dfs2(int u,int par,int dist){
    total+=dist;

    for(auto v:adj[u]){
        if(v==par)continue;

        dfs2(v,u,dist+1);
    }
}

void dfs3(int u,int par){
    for(auto v:adj[u]){
        if(v==par)continue;

        ans[v]=ans[u]+n-2*sub[v];

        dfs3(v,u);
    }
}

int main(){
    cin>>n;

    adj.resize(n+1);
    sub.resize(n+1);
    ans.resize(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1,0);

    dfs2(1,0,0);
    ans[1]=total;

    dfs3(1,0);

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;
}