#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long binpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int mx=1000000;

    vector<long long>fact(mx+1),invfact(mx+1);

    fact[0]=1;
    for(int i=1;i<=mx;i++)
        fact[i]=fact[i-1]*i%mod;

    invfact[mx]=binpow(fact[mx],mod-2);

    for(int i=mx;i>=1;i--)
        invfact[i-1]=invfact[i]*i%mod;

    while(n--){
        int a,b;
        cin>>a>>b;

        cout<<fact[a]*invfact[b]%mod*invfact[a-b]%mod<<'\n';
    }
}