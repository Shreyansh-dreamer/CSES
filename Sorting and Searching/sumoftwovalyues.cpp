#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;

    vector<pair<long long,int>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a.begin(),a.end());

    int i=0,j=n-1;

    while(i<j){
        long long sum=a[i].first+a[j].first;

        if(sum==x){
            cout<<a[i].second<<" "<<a[j].second<<endl;
            return 0;
        }
        else if(sum<x){
            i++;
        }
        else{
            j--;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}