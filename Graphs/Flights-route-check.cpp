#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x])dfs(x,adj,vis,st);
    }
    st.push(node);
}

void dfs2(int node,vector<vector<int>>&rev,vector<int>&vis,vector<int>&comp,int id){
    vis[node]=1;
    comp[node]=id;
    for(auto x:rev[node]){
        if(!vis[x])dfs2(x,rev,vis,comp,id);
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1),rev(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int>vis(n+1,0);
    stack<int>st;

    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,adj,vis,st);
    }

    fill(vis.begin(),vis.end(),0);

    vector<int>comp(n+1);
    int id=0;

    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(!vis[node]){
            id++;
            dfs2(node,rev,vis,comp,id);
        }
    }

    if(id==1){
        cout<<"YES"<<endl;
        return 0;
    }

    int a=1,b=-1;

    for(int i=2;i<=n;i++){
        if(comp[i]!=comp[a]){
            b=i;
            break;
        }
    }

    vector<int>check(n+1,0);
    dfs(a,adj,check,st);

    if(!check[b]){
        cout<<"NO"<<endl;
        cout<<a<<" "<<b<<endl;
    }
    else{
        cout<<"NO"<<endl;
        cout<<b<<" "<<a<<endl;
    }
}