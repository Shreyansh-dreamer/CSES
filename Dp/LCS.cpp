#include<bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int dp(int i,int j,vector<int>& arr1,vector<int>& arr2){
    if(i==arr1.size() || j==arr2.size())return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    int ans=0;
    if(arr1[i]==arr2[j])ans=1+dp(i+1,j+1,arr1,arr2);
    else{
        ans=max(ans,dp(i+1,j,arr1,arr2));
        ans=max(ans,dp(i,j+1,arr1,arr2));
    }
    return memo[i][j]=ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n),arr2(m);
    for(int i=0;i<n;i++)cin>>arr1[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    memset(memo,-1,sizeof(memo));
    int x=dp(0,0,arr1,arr2);
    cout<<x<<endl;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(dp(i+1,j,arr1,arr2)>dp(i,j+1,arr1,arr2)){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<endl;
    return 0;
}