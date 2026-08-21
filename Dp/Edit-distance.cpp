#include<bits/stdc++.h>
using namespace std;

int memo[5002][5002];

int dp(int i,int j,string& a,string& b){
    if(i==a.size() && j==b.size())return 0;
    if(i==a.size())return b.size()-j;
    if(j==b.size())return a.size()-i;
    if(memo[i][j]!=-1)return memo[i][j];
    int ans=INT_MAX;
    if(a[i]==b[j])ans=dp(i+1,j+1,a,b);
    else{
        ans=min(ans,1+dp(i+1,j,a,b));
        ans=min(ans,1+dp(i,j+1,a,b));
        ans=min(ans,1+dp(i+1,j+1,a,b));
    }
    return memo[i][j]=ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin>>s1>>s2;
    memset(memo,-1,sizeof(memo));
    cout<<dp(0,0,s1,s2)<<endl;
    return 0;
}