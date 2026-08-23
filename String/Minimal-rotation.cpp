#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int n=s.size();
    s+=s;

    const long long mod1=1000000007;
    const long long mod2=1000000009;
    const long long base=31;

    vector<long long> pow1(2*n+1,1),pow2(2*n+1,1);
    vector<long long> pref1(2*n+1,0),pref2(2*n+1,0);

    for(int i=0;i<2*n;i++){
        pow1[i+1]=pow1[i]*base%mod1;
        pow2[i+1]=pow2[i]*base%mod2;

        pref1[i+1]=(pref1[i]*base+(s[i]-'a'+1))%mod1;
        pref2[i+1]=(pref2[i]*base+(s[i]-'a'+1))%mod2;
    }

    auto getHash1=[&](int l,int len){
        long long h=(pref1[l+len]-pref1[l]*pow1[len])%mod1;
        if(h<0)
            h+=mod1;
        return h;
    };

    auto getHash2=[&](int l,int len){
        long long h=(pref2[l+len]-pref2[l]*pow2[len])%mod2;
        if(h<0)
            h+=mod2;
        return h;
    };

    int best=0;

    for(int i=1;i<n;i++){
        int lo=0,high=n-1;
        int pos=n;

        while(lo<=high){
            int mid=lo+(high-lo)/2;

            if(getHash1(best,mid+1)==getHash1(i,mid+1) &&
               getHash2(best,mid+1)==getHash2(i,mid+1)){
                lo=mid+1;
            }
            else{
                pos=mid;
                high=mid-1;
            }
        }

        if(pos<n && s[i+pos]<s[best+pos])
            best=i;
    }

    cout<<s.substr(best,n)<<'\n';

    return 0;
}