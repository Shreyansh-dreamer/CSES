#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int memo[501][501];

int dp(int a,int b){
    if(a==b)return 0;
    if(memo[a][b]!=-1)return memo[a][b];
    int ans=1000000;
    for(int i=1;i<a;i++){
        ans=min(ans,1+dp(i,b)+dp(a-i,b));
    }
    for(int i=1;i<b;i++){
        ans=min(ans,1+dp(a,i)+dp(a,b-i));
    }
    return memo[a][b]=ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            memo[i][j]=-1;
        }
    }
    cout<<dp(a,b)<<endl;
    return 0;
}