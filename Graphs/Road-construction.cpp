#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int>par,compsize;

    DSU(int n){
        par.resize(n+1);
        compsize.resize(n+1,1);
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

        if(compsize[a]<compsize[b])swap(a,b);

        par[b]=a;
        compsize[a]+=compsize[b];

        return true;
    }
};

int main(){
    int n,m;
    cin>>n>>m;

    DSU dsu(n);

    int comp=n;
    int largest=1;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        if(dsu.unite(a,b)){
            comp--;
            a=dsu.find(a);
            largest=max(largest,dsu.compsize[a]);
        }

        cout<<comp<<" "<<largest<<endl;
    }
}