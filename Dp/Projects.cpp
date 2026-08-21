#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<pair<int,int>,int>> a;
vector<long long> dp;

int bs(int ind){
    int l=ind+1,r=a.size()-1;
    int ans=a.size();

    while(l<=r){
        int m=(l+r)/2;
        if(a[m].first.first>a[ind].first.second){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}

long long solve(int ind){
    if(ind==a.size())
        return 0;

    if(dp[ind]!=-1)
        return dp[ind];

    long long notTake=solve(ind+1);
    int nxt=bs(ind);
    long long take=a[ind].second+solve(nxt);

    return dp[ind]=max(take,notTake);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    a.resize(n);

    for(int i=0;i<n;i++){
        int s,e,p;
        cin>>s>>e>>p;
        a[i]={{s,e},p};
    }

    sort(a.begin(),a.end());
    dp.assign(n,-1);

    cout<<solve(0)<<endl;

    return 0;
}