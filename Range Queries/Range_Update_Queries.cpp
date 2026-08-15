#include<bits/stdc++.h>
using namespace std; 

vector<long long>seg,lazy;

void build(int node,int start,int end,vector<int>&arr){
    if(start==end){
        seg[node]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(2*node+1,start,mid,arr);
    build(2*node+2,mid+1,end,arr);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}

void update(int node,int l,int r,int left,int right,long long val){
    if(lazy[node]!=0){
        seg[node]+=lazy[node]*(r-l+1);
        if(l!=r){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(r<left || l>right)return;
    if(l>=left && r<=right){
        seg[node]+=val*(r-l+1);
        if(l!=r){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return;
    }
    int mid=l+(r-l)/2;
    update(2*node+1,l,mid,left,right,val);
    update(2*node+2,mid+1,r,left,right,val);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}

long long find(int ind,int l,int r,int pos){
    if(lazy[ind]!=0){
        seg[ind]+=lazy[ind]*(r-l+1);
        if(l!=r){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l==r)return seg[ind];
    int mid=l+(r-l)/2;
    if(pos<=mid)return find(2*ind+1,l,mid,pos);
    else return find(2*ind+2,mid+1,r,pos);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    seg.resize(4*n);
    lazy.resize(4*n);
    build(0,0,n-1,arr);
    while(q--){
        int type;
        cin>>type;
        if(type==2){
            int k;
            cin>>k;
            cout<<find(0,0,n-1,k-1)<<'\n';
        }
        else{
            int a,b;
            long long u;
            cin>>a>>b>>u;
            a--;
            b--;
            update(0,0,n-1,a,b,u);
        }
    }
    return 0;
}