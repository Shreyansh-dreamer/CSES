#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int par,int dis,vector<vector<int>>&adj,vector<int>&dist){
    dist[node]=dis;
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,node,dis+1,adj,dist);
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist(n+1,0);
    dfs(1,0,0,adj,dist);
    int node=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>dist[node])node=i;
    }
    fill(dist.begin(),dist.end(),0);
    dfs(node,0,0,adj,dist);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
    }
    cout<<ans<<endl;
    return 0;
}