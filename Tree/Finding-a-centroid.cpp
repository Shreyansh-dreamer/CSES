#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;
    }

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(deg[i]==1)
            q.push(i);
    }

    int remaining=n;

    while(remaining>2){
        int sz=q.size();

        while(sz--){
            int u=q.front();
            q.pop();

            remaining--;

            for(int v:adj[u]){
                if(deg[v]>0){
                    deg[v]--;

                    if(deg[v]==1)
                        q.push(v);
                }
            }

            deg[u]=0;
        }
    }

    cout<<q.front()<<endl;
}