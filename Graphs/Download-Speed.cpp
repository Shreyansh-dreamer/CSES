#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<vector<long long>>cap;
vector<int>level,ptr;

bool bfs(int s,int t){
    fill(level.begin(),level.end(),-1);
    queue<int>q;
    q.push(s);
    level[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(level[v]==-1 && cap[u][v]>0){
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return level[t]!=-1;
}

long long dfs(int u,int t,long long flow){
    if(u==t)return flow;
    for(int &i=ptr[u];i<adj[u].size();i++){
        int v=adj[u][i];
        if(level[v]!=level[u]+1 || cap[u][v]==0)
            continue;
        long long pushed=dfs(v,t,min(flow,cap[u][v]));
        if(pushed){
            cap[u][v]-=pushed;
            cap[v][u]+=pushed;
            return pushed;
        }
    }
    return 0;
}

long long dinic(int s,int t){
    long long ans=0;
    while(bfs(s,t)){
        fill(ptr.begin(),ptr.end(),0);
        while(true){
            long long pushed=dfs(s,t,1e18);
            if(!pushed)break;
            ans+=pushed;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    cap.assign(n,vector<long long>(n,0));
    level.resize(n);
    ptr.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b]+=c;
    }
    cout<<dinic(0,n-1)<<endl;
}