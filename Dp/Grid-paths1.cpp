#include<bits/stdc++.h>
using namespace std;

int n;
int mod=1e9+7;
vector<string>grid;
vector<vector<int>>memo;

int dp(int r,int c){
    if(r<0 || c<0)return 0;
    if(grid[r][c]=='*')return 0;
    if(r==0 && c==0)return 1;

    if(memo[r][c]!=-1)return memo[r][c];

    return memo[r][c]=(dp(r-1,c)+dp(r,c-1))%mod;
}

int main(){
    cin>>n;

    grid.resize(n);
    for(int i=0;i<n;i++)cin>>grid[i];

    memo.assign(n,vector<int>(n,-1));

    cout<<dp(n-1,n-1)<<endl;
}