#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> seg,arr,cnt;

void update(int node,int l,int r,int ind,int val){
    if(l==r){
        cnt[ind]+=val;
        seg[node]=(cnt[ind]>0);
        return;
    }

    int mid=(l+r)/2;

    if(ind<=mid) update(2*node+1,l,mid,ind,val);
    else update(2*node+2,mid+1,r,ind,val);

    seg[node]=seg[2*node+1]+seg[2*node+2];
}

int query(int node,int l,int r){
    if(l==r) return l;

    int mid=(l+r)/2;

    if(seg[2*node+1]<mid-l+1)
        return query(2*node+1,l,mid);

    return query(2*node+2,mid+1,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    arr.resize(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    seg.assign(4*(k+1),0);
    cnt.assign(k+1,0);

    for(int i=0;i<k;i++){
        if(arr[i]<=k) update(0,0,k,arr[i],1);
    }

    for(int i=0;i+k<=n;i++){
        cout<<query(0,0,k)<<" ";

        if(i+k<n){
            if(arr[i]<=k) update(0,0,k,arr[i],-1);
            if(arr[i+k]<=k) update(0,0,k,arr[i+k],1);
        }
    }

    cout<<endl;
}