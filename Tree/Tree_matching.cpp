#include<bits/stdc++.h>
using namespace std;

int dp(int node,int parent,int taken,vector<vector<int>>&adj){
    if(adj[node].size()==1 && adj[node][0]==parent){
        return taken;
    }
    int ans=
    return ans;
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
    cout<<dp(1,0,0,adj)<<endl;
    return 0;
}