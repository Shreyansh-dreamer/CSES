#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    long long x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<long long>arr(k);
    arr[0]=x;

    int cnt[30]={0};
    long long cur=0,ans=0;

    for(int i=0;i<k;i++){
        if(i){
            x=(a*x+b)%c;
            arr[i]=x;
        }

        long long z=arr[i];

        while(z){
            int j=__builtin_ctzll(z);
            cnt[j]++;
            cur|=1LL<<j;
            z-=1LL<<j;
        }
    }

    ans^=cur;

    for(int i=k;i<n;i++){
        x=(a*x+b)%c;

        int pos=i%k;

        long long z=arr[pos];

        while(z){
            int j=__builtin_ctzll(z);
            cnt[j]--;

            if(cnt[j]==0)
                cur^=1LL<<j;

            z-=1LL<<j;
        }

        arr[pos]=x;

        z=x;

        while(z){
            int j=__builtin_ctzll(z);

            if(cnt[j]==0)
                cur|=1LL<<j;

            cnt[j]++;
            z-=1LL<<j;
        }

        ans^=cur;
    }

    cout<<ans<<endl;
}