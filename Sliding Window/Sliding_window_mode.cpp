#include<bits/stdc++.h>
using namespace std;

vector<int> seg,freq;

void build(int node,int l,int r){
    if(l==r){
        seg[node]=l;
        return;
    }

    int mid=(l+r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    int left=seg[2*node+1],right=seg[2*node+2];
    if(freq[left]>=freq[right])seg[node]=left;
    else seg[node]=right;
}

void update(int node,int l,int r,int ind){
    if(l==r)return;

    int mid=(l+r)/2;
    if(ind<=mid)update(2*node+1,l,mid,ind);
    else update(2*node+2,mid+1,r,ind);

    int left=seg[2*node+1],right=seg[2*node+2];
    if(freq[left]>=freq[right])seg[node]=left;
    else seg[node]=right;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<int> vals=arr;
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    int m=vals.size();
    freq.resize(m,0);
    seg.resize(4*m);

    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin();
    }

    for(int i=0;i<k;i++)freq[a[i]]++;

    build(0,0,m-1);

    cout<<vals[seg[0]];

    for(int i=k;i<n;i++){
        freq[a[i-k]]--;
        update(0,0,m-1,a[i-k]);

        freq[a[i]]++;
        update(0,0,m-1,a[i]);

        cout<<" "<<vals[seg[0]];
    }

    cout<<endl;
}