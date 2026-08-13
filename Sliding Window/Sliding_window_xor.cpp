#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    long long x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<long long>arr(n);
    arr[0]=x;

    for(int i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+b)%c;
    }

    vector<long long>pref(n+1,0);

    for(int i=0;i<n;i++)
        pref[i+1]=pref[i]^arr[i];

    long long ans=0;

    for(int i=k;i<=n;i++){
        long long cur=pref[i]^pref[i-k];
        ans^=cur;
    }

    cout<<ans<<endl;
}