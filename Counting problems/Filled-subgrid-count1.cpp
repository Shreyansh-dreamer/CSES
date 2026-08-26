#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<string> a(n);
    for(auto &x:a) cin>>x;

    vector<vector<int>> dp(n+1,vector<int>(n+1,1));
    vector<long long> ans(k);

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i+1<n && j+1<n &&
               a[i][j]==a[i+1][j] &&
               a[i][j]==a[i][j+1] &&
               a[i][j]==a[i+1][j+1])
                dp[i][j]=1+min({
                    dp[i+1][j],
                    dp[i][j+1],
                    dp[i+1][j+1]
                });

            ans[a[i][j]-'A']+=dp[i][j];
        }
    }

    for(int i=0;i<k;i++)
        cout<<ans[i]<<"\n";
}