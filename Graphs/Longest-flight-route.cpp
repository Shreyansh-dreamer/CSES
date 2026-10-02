#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int>dist(n+1,-1);
    vector<int>par(n+1,-1);
    priority_queue<pair<int,int>>pq;
    dist[1]=1;
    pq.push({1,1});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(d<dist[u])continue;
        for(int v:adj[u]){
            if(dist[v]<d+1){
                dist[v]=d+1;
                par[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>ans;
    int cur=n;
    while(cur!=-1){
        ans.push_back(cur);
        cur=par[cur];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int x:ans)cout<<x<<" ";
    cout<<endl;
}