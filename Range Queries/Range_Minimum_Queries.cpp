#include<bits/stdc++.h>
using namespace std;

vector<int>seg;

void build(int node,int start,int end,vector<int>&arr){
    if(start==end){
        seg[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(2*node+1,start,mid,arr);
    build(2*node+2,mid+1,end,arr);
    seg[node]=min(seg[2*node+1],seg[2*node+2]);
}

int find(int ind,int l,int r,int left,int right){
    if(r<left || l>right)return INT_MAX;
    if(l>=left && r<=right)return seg[ind];
    int mid=l+(r-l)/2;
    return min(
        find(2*ind+1,l,mid,left,right),
        find(2*ind+2,mid+1,r,left,right)
    );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    seg.resize(4*n);
    build(0,0,n-1,arr);
    while(q--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int x=find(0,0,n-1,a,b);
        cout<<x<<'\n';
    }
    return 0;
}