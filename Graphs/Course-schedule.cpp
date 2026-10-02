#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>indeg(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }

    vector<int>ans;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);

        for(int v:adj[u]){
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }

    if(ans.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    for(int x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}