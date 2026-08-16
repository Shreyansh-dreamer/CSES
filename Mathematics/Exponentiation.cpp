#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

long long binpow(long long a,long long b){
    if(b==0)return 1;
    long long res=binpow(a,b/2);
    res=res*res%mod;
    if(b&1)res=res*a%mod;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while(n--){
        long long a,b;
        cin>>a>>b;
        cout<<binpow(a,b)<<'\n';
    }
}