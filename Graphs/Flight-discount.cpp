#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const ll INF=4e18;

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>>& adj){
    int n=adj.size()-1;
    vector<ll> dist(n+1,INF);

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d!=dist[u]) continue;

        for(auto [v,w]:adj[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,ll>>> adj(n+1),rev(n+1);
    vector<tuple<int,int,ll>> edges;

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        rev[v].push_back({u,w});
        edges.push_back({u,v,w});
    }

    vector<ll> d1=dijkstra(1,adj);
    vector<ll> d2=dijkstra(n,rev);

    ll ans=INF;

    for(auto [u,v,w]:edges){
        ans=min(ans,d1[u]+w/2+d2[v]);
    }

    cout<<ans<<"\n";
}