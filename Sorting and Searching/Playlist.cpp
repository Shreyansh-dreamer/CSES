#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_map<int,int> mpp;
    mpp.reserve(2*n);

    int l=0,ans=0;

    for(int r=0;r<n;r++){
        if(mpp.count(a[r])){
            l=max(l,mpp[a[r]]+1);
        }

        mpp[a[r]]=r;
        ans=max(ans,r-l+1);
    }

    cout<<ans<<endl;
    return 0;
}