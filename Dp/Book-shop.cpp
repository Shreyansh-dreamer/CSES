#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int>h(n),s(n);

    int total=0,sum=0;

    for(int i=0;i<n;i++){
        cin>>h[i];
        total+=h[i];
    }

    for(int i=0;i<n;i++){
        cin>>s[i];
        sum+=s[i];
    }

    if(total<=x){
        cout<<sum<<endl;
        return 0;
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));

    for(int i=n-1;i>=0;i--){
        for(int price=0;price<=x;price++){
            dp[i][price]=dp[i+1][price];

            if(price+h[i]<=x)
                dp[i][price]=max(dp[i][price],
                                  s[i]+dp[i+1][price+h[i]]);
        }
    }

    cout<<dp[0][0]<<endl;
}