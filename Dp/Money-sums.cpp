#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> coins(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        sum+=coins[i];
    }
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(int x:coins){
        for(int s=sum;s>=x;s--){
            if(dp[s-x]){
                dp[s]=true;
            }
        }
    }
    vector<int> ans;
    for(int s=1;s<=sum;s++){
        if(dp[s]){
            ans.push_back(s);
        }
    }
    cout<<ans.size()<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}