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

    long long sum=0,ans=0;

    for(int i=0;i<k;i++)
        sum+=arr[i];

    ans^=sum;

    for(int i=k;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        ans^=sum;
    }

    cout<<ans<<endl;
}