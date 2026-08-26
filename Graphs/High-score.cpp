#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v;
    long long w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<Edge> edges;
    vector<vector<int>> rev(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        long long x;
        cin>>a>>b>>x;

        edges.push_back({a,b,x});
        rev[b].push_back(a);
    }

    vector<int> canReach(n+1);
    queue<int> q;

    q.push(n);
    canReach[n]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:rev[u]){
            if(!canReach[v]){
                canReach[v]=1;
                q.push(v);
            }
        }
    }

    const long long INF=4e18;
    vector<long long> dist(n+1,-INF);
    dist[1]=0;

    for(int i=1;i<=n;i++){
        bool changed=false;

        for(auto [u,v,w]:edges){
            if(dist[u]==-INF) continue;

            if(dist[v]<dist[u]+w){
                dist[v]=dist[u]+w;
                changed=true;

                if(i==n && canReach[v]){
                    cout<<-1<<"\n";
                    return 0;
                }
            }
        }

        if(!changed) break;
    }

    cout<<dist[n]<<"\n";
}