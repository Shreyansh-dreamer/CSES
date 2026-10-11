#include<bits/stdc++.h>
using namespace std;

multiset<int> low,high;

void balance(){
    if(!low.empty() && !high.empty() && *low.rbegin()>*high.begin()){
        int x=*low.rbegin();
        int y=*high.begin();

        low.erase(prev(low.end()));
        high.erase(high.begin());

        low.insert(y);
        high.insert(x);
    }

    while(low.size()>high.size()+1){
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
    }

    while(low.size()<high.size()){
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<n;i++){
        if(i>=k){
            int x=arr[i-k];
            auto it=low.find(x);
            if(it!=low.end())low.erase(it);
            else high.erase(high.find(x));
        }

        if(low.size()>high.size())high.insert(arr[i]);
        else low.insert(arr[i]);

        balance();

        if(i>=k-1)cout<<*low.rbegin()<<" ";
    }

    cout<<endl;
}