#include <bits/stdc++.h>
using namespace std;

vector<unsigned int> seg;

void build(vector<unsigned int>& arr,int node,int l,int r){
    if(l==r){
        seg[node]=arr[l];
        return;
    }

    int mid=(l+r)/2;
    build(arr,2*node+1,l,mid);
    build(arr,2*node+2,mid+1,r);

    seg[node]=seg[2*node+1]|seg[2*node+2];
}

unsigned int query(int node,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return seg[node];
    if(r<ql||l>qr) return 0;

    int mid=(l+r)/2;

    return query(2*node+1,l,mid,ql,qr)|
           query(2*node+2,mid+1,r,ql,qr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    long long x,a,b,c;
    cin>>n>>k>>x>>a>>b>>c;

    vector<unsigned int> arr(n);
    arr[0]=x;

    for(int i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+b)%c;
    }

    seg.resize(4*n);
    build(arr,0,0,n-1);

    unsigned int ans=0;

    for(int i=0;i+k<=n;i++){
        ans^=query(0,0,n-1,i,i+k-1);
    }

    cout<<ans<<endl;
}