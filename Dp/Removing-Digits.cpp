#include<bits/stdc++.h>
using namespace std;

vector<int> memo;

int dp(int n){
    if(n==0)return 0;

    if(memo[n]!=-1)return memo[n];

    int x=n;
    int ans=1e9;

    while(x){
        int d=x%10;
        x/=10;

        if(d)
            ans=min(ans,1+dp(n-d));
    }

    return memo[n]=ans;
}

int main(){
    int n;
    cin>>n;

    memo.assign(n+1,-1);

    cout<<dp(n)<<endl;
}