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
    int n;
    cin>>n;

    vector<long long>fact(n+1),invfact(n+1);

    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%mod;

    invfact[n]=binpow(fact[n],mod-2);

    for(int i=n;i>=1;i--)
        invfact[i-1]=invfact[i]*i%mod;

    long long sum=0;

    for(int i=0;i<=n;i++){
        if(i&1)
            sum=(sum-invfact[i]+mod)%mod;
        else
            sum=(sum+invfact[i])%mod;
    }

    cout<<fact[n]*sum%mod<<endl;
}