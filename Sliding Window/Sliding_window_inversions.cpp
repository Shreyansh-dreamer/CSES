#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> seg;

void update(int node,int l,int r,int ind,int val){
    if(l==r){
        seg[node]+=val;
        return;
    }

    int mid=(l+r)/2;

    if(ind<=mid) update(2*node+1,l,mid,ind,val);
    else update(2*node+2,mid+1,r,ind,val);

    seg[node]=seg[2*node+1]+seg[2*node+2];
}

int query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l) return 0;
    if(ql<=l&&r<=qr) return seg[node];

    int mid=(l+r)/2;

    return query(2*node+1,l,mid,ql,qr)
          +query(2*node+2,mid+1,r,ql,qr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;

    vector<int> arr(n),v;
    for(int i=0;i<n;i++) cin>>arr[i];

    v=arr;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    vector<int> rank(n);

    for(int i=0;i<n;i++){
        rank[i]=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
    }

    int m=v.size();
    seg.assign(4*m,0);

    long long ans=0;

    for(int i=0;i<k;i++){
        ans+=query(0,0,m-1,rank[i]+1,m-1);
        update(0,0,m-1,rank[i],1);
    }

    cout<<ans<<" ";

    for(int i=k;i<n;i++){
        int rem=rank[i-k];

        update(0,0,m-1,rem,-1);
        ans-=query(0,0,m-1,0,rem-1);

        ans+=query(0,0,m-1,rank[i]+1,m-1);
        update(0,0,m-1,rank[i],1);

        cout<<ans<<" ";
    }

    cout<<endl;
}