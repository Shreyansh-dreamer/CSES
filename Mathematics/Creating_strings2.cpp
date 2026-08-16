#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;

int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int32_t main(){
    string s;
    cin>>s;

    int n=s.size();

    vector<int>fact(n+1),invfact(n+1);

    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%mod;

    invfact[n]=power(fact[n],mod-2);

    for(int i=n-1;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%mod;

    vector<int>freq(26,0);

    for(char c:s)
        freq[c-'a']++;

    int ans=fact[n];

    for(int i=0;i<26;i++)
        ans=ans*invfact[freq[i]]%mod;

    cout<<ans<<"\n";
}