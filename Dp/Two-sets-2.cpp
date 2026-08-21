#include<iostream>
#include<vector>
using namespace std;

const long long MOD=1000000007;

long long memo[501][63000];

long long dp(int i,int sum){
    if(sum==0)return 1;
    if(i==0)return 0;
    if(memo[i][sum]!=-1){
        return memo[i][sum];
    }
    long long ans=dp(i-1,sum);
    if(sum>=i){
        ans+=dp(i-1,sum-i);
        ans%=MOD;
    }
    return memo[i][sum]=ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long long total=1LL*n*(n+1)/2;
    if(total%2){
        cout<<0<<endl;
        return 0;
    }
    int target=total/2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            memo[i][j]=-1;
        }
    }
    long long ways=dp(n,target);
    cout<<ways*500000004%MOD<<endl;
    return 0;
}