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
    vector<int>dist1(n+1),dist2(n+1);
    dfs(1,0,0,adj,dist1);
    int node=1;
    for(int i=1;i<=n;i++){
        if(dist1[i]>dist1[node])node=i;
    }
    dfs(node,0,0,adj,dist1);
    int node2=1;
    for(int i=1;i<=n;i++){
        if(dist1[i]>dist1[node2])node2=i;
    }
    dfs(node2,0,0,adj,dist2);
    for(int i=1;i<=n;i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }
    cout<<endl;
}