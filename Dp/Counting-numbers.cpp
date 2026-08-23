#include <bits/stdc++.h>
using namespace std;

long long dp[20][11][2][2];
string s;

long long solve(int pos,int prev,int tight,int started){
    if(pos==s.size())
        return 1;

    if(dp[pos][prev][tight][started]!=-1)
        return dp[pos][prev][tight][started];

    int limit=s[pos]-'0';
    if(!tight)limit=9;

    long long ans=0;

    for(int d=0;d<=limit;d++){
        int ntight=tight&&(d==limit);

        if(!started && d==0){
            ans+=solve(pos+1,10,ntight,0);
        }
        else{
            if(started && d==prev)
                continue;

            ans+=solve(pos+1,d,ntight,1);
        }
    }

    return dp[pos][prev][tight][started]=ans;
}

long long count(long long x){
    if(x<0)return 0;

    s=to_string(x);
    memset(dp,-1,sizeof(dp));

    return solve(0,10,1,0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b;
    cin>>a>>b;

    cout<<count(b)-count(a-1)<<'\n';

    return 0;
}