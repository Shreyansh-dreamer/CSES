#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1,-1);
    vector<int> prev(n+1,-1);

    queue<int> q;
    q.push(1);
    dist[1]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v:adj[u]){
            if(dist[v]!=-1) continue;

            dist[v]=dist[u]+1;
            prev[v]=u;
            q.push(v);
        }
    }

    if(dist[n]==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;

    int cur=n;
    while(cur!=-1){
        path.push_back(cur);
        cur=prev[cur];
    }

    reverse(path.begin(),path.end());

    cout<<path.size()<<"\n";

    for(int x:path)
        cout<<x<<" ";
    cout<<"\n";
}