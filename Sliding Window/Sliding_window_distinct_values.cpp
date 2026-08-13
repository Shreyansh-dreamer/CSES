#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector<int>v=arr;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    vector<int>cnt(v.size(),0);

    for(int i=0;i<k;i++){
        int pos=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        cnt[pos]++;
    }

    int distinct=0;

    for(int i=0;i<cnt.size();i++){
        if(cnt[i])
            distinct++;
    }

    cout<<distinct<<" ";

    for(int i=k;i<n;i++){
        int in=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
        int out=lower_bound(v.begin(),v.end(),arr[i-k])-v.begin();

        if(cnt[out]==1)
            distinct--;

        cnt[out]--;

        if(cnt[in]==0)
            distinct++;

        cnt[in]++;

        cout<<distinct<<" ";
    }

    cout<<endl;
}