#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> left(n),right(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
        right[i]=st.empty()?n:st.top();
        st.push(i);
    }

    for(int i=0;i+k<=n;i++){
        long long ans=0;

        for(int j=i;j<i+k;j++){
            long long width=min((long long)k,(long long)right[j]-left[j]-1);
            ans=max(ans,arr[j]*width);
        }

        cout<<ans<<" ";
    }

    cout<<endl;
}