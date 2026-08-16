#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long binpow(long long a,long long b,long long m){
    if(b==0)return 1%m;
    long long res=binpow(a,b/2,m);
    res=res*res%m;
    if(b&1)res=res*a%m;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while(n--){
        long long a,b,c;
        cin>>a>>b>>c;

        long long x=binpow(b,c,mod-1);
        cout<<binpow(a,x,mod)<<'\n';
    }
}