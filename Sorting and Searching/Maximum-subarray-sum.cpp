#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    long long ans=LLONG_MIN,sum=0;

    for(int i=0;i<n;i++){
        long long x;
        cin>>x;

        sum=max(x,sum+x);
        ans=max(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}