#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<long long> a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];

    int ans=1;
    int cnt=1;
    long long mx=a[0];

    for(int i=1;i<n;i++){
        if(a[i]>=mx){
            ans=max(ans,cnt);
            cnt=1;
            mx=a[i];
        }
        else{
            cnt++;
        }
    }

    ans=max(ans,cnt);

    cout<<ans<<endl;

    return 0;
}