#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,ll>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    vector<vector<ll>> dist(n+1);

    pq.push({0,1});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(dist[u].size()>=k)
            continue;

        dist[u].push_back(d);

        for(auto [v,w]:adj[u]){
            if(dist[v].size()<k)
                pq.push({d+w,v});
        }
    }

    for(int i=0;i<k;i++)
        cout<<dist[n][i]<<" ";
}