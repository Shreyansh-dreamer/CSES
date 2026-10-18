#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    unordered_set<int> st;
    long long ans=0;
    int l=0;

    for(int r=0;r<n;r++){
        while(st.count(arr[r])){
            st.erase(arr[l]);
            l++;
        }
        st.insert(arr[r]);
        ans+=r-l+1;
    }

    cout<<ans<<endl;
}