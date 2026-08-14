#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<vector<int>>up;
vector<int>depth;
int n,q;

void dfs(int u,int par,int d){
    up[u][0]=par;
    depth[u]=d;

    for(auto v:adj[u]){
        if(v==par)continue;

        dfs(v,u,d+1);
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a,b);

    int diff=depth[a]-depth[b];

    for(int j=up[0].size()-1;j>=0;j--){
        if((diff>>j)&1)
            a=up[a][j];
    }

    if(a==b)return a;

    for(int j=up[0].size()-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }

    return up[a][0];
}

int main(){
    cin>>n>>q;

    int lg=0;
    while((1<<lg)<=n)lg++;

    adj.resize(n+1);
    up.resize(n+1,vector<int>(lg));
    depth.resize(n+1);

    for(int i=2;i<=n;i++){
        int p;
        cin>>p;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1,0,0);

    for(int j=1;j<lg;j++){
        for(int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        cout<<lca(a,b)<<endl;
    }
}