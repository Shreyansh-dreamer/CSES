#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int>par,sz;

    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++)par[i]=i;
    }

    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(sz[a]<sz[b])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<array<long long,3>>edges(m);

    for(int i=0;i<m;i++){
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }

    sort(edges.begin(),edges.end());

    DSU dsu(n);
    long long ans=0;
    int cnt=0;

    for(auto &it:edges){
        long long cost=it[0];
        int a=it[1];
        int b=it[2];

        if(dsu.unite(a,b)){
            ans+=cost;
            cnt++;
        }
    }

    if(cnt!=n-1)cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;

    return 0;
}