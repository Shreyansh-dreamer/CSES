#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,long long>>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    const long long INF=4e18;
    vector<long long> dist(n+1,INF);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dist[1]=0;
    pq.push({0,1});

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

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}