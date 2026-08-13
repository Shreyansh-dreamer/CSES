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

    deque<int>dq;
    long long ans=0;

    for(int i=0;i<n;i++){
        while(!dq.empty() && arr[dq.back()]>=arr[i])
            dq.pop_back();

        dq.push_back(i);

        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();

        if(i>=k-1)
            ans^=arr[dq.front()];
    }

    cout<<ans<<endl;
}