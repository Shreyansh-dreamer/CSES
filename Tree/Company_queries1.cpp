#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<vector<int>>up;
int n,q;

void dfs(int u,int par){
    up[u][0]=par;

    for(auto v:adj[u]){
        if(v==par)continue;

        dfs(v,u);
    }
}

int main(){
    cin>>n>>q;

    int lg=0;
    while((1<<lg)<=n)lg++;

    adj.resize(n+1);
    up.resize(n+1,vector<int>(lg));

    for(int i=2;i<=n;i++){
        int p;
        cin>>p;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1,0);

    for(int j=1;j<lg;j++){
        for(int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;

        for(int j=lg-1;j>=0;j--){
            if((k>>j)&1)
                x=up[x][j];
        }

        if(x==0)cout<<-1<<endl;
        else cout<<x<<endl;
    }
}