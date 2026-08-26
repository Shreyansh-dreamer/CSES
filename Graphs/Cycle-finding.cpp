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

    vector<Edge> edges(m);

    for(auto &e:edges)
        cin>>e.u>>e.v>>e.w;

    const long long INF=4e18;

    vector<long long> dist(n+1,0);
    vector<int> parent(n+1,-1);

    int x=-1;

    for(int i=1;i<=n;i++){
        x=-1;

        for(auto [u,v,w]:edges){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                x=v;
            }
        }
    }

    if(x==-1){
        cout<<"NO\n";
        return 0;
    }

    for(int i=0;i<n;i++)
        x=parent[x];

    vector<int> cycle;

    int cur=x;

    do{
        cycle.push_back(cur);
        cur=parent[cur];
    }while(cur!=x);

    cycle.push_back(x);

    reverse(cycle.begin(),cycle.end());

    cout<<"YES\n";

    for(int v:cycle)
        cout<<v<<" ";

    cout<<"\n";
}