#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<long long> memo;

long long dp(int u){
    if(u==1)return 1;
    if(memo[u]!=-1)return memo[u];

    long long ans=0;

    for(int v:adj[u]){
        ans=(ans+dp(v))%1000000007;
    }

    return memo[u]=ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    memo.resize(n+1,-1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }

    cout<<dp(n)<<endl;
}