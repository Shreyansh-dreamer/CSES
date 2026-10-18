
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    long long sum=1;
    for(int i=0;i<n;i++){
        if(a[i]>sum) break;
        sum+=a[i];
    }

    cout<<sum<<endl;
    return 0;
}
