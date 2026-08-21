#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long memo[5001][5001];

long long dp(int l,int r,vector<long long>& a){
    if(l==r)return a[l];
    if(memo[l][r]!=-1)return memo[l][r];
    long long x=a[l]-dp(l+1,r,a);
    long long y=a[r]-dp(l,r-1,a);
    return memo[l][r]=max(x,y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<long long> a(n);
    long long total=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            memo[i][j]=-1;
        }
    }
    long long diff=dp(0,n-1,a);
    long long first=(total+diff)/2;
    cout<<first<<endl;
    return 0;
}