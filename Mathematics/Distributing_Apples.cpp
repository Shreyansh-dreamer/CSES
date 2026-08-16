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

int ncr(int n,int r){
    if(r>n)return 0;

    int num=1,den=1;

    for(int i=1;i<=r;i++){
        num=num*(n-r+i)%mod;
        den=den*i%mod;
    }

    return num*power(den,mod-2)%mod;
}

int32_t main(){
    int n,m;
    cin>>n>>m;

    cout<<ncr(n+m-1,m)<<"\n";
}