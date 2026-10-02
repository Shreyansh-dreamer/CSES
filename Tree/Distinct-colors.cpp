#include<bits/stdc++.h>
using namespace std;

const int N=200005;

vector<int> adj[N];
int color[N];
int ans[N];

unordered_map<int,int>* dfs(int u,int p){
    auto *mp=new unordered_map<int,int>();

    (*mp)[color[u]]++;

    for(int v:adj[u]){
        if(v==p)
            continue;

        auto *child=dfs(v,u);

        if(mp->size()<child->size())
            swap(mp,child);

        for(auto x:*child)
            (*mp)[x.first]+=x.second;

        delete child;
    }

    ans[u]=mp->size();

    return mp;
}

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>color[i];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;
}