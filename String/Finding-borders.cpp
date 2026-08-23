#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int n=s.size();
    const long long mod=1000000007;
    const long long base=31;

    vector<long long> power(n+1,1);
    vector<long long> pref(n+1,0);

    for(int i=0;i<n;i++){
        power[i+1]=(power[i]*base)%mod;
        pref[i+1]=(pref[i]*base+(s[i]-'a'+1))%mod;
    }

    vector<int> ans;

    for(int len=1;len<n;len++){
        long long pre=pref[len];
        long long suf=(pref[n]-pref[n-len]*power[len])%mod;

        if(suf<0)suf+=mod;

        if(pre==suf)
            ans.push_back(len);
    }

    for(int x:ans)
        cout<<x<<" ";

    cout<<'\n';

    return 0;
}