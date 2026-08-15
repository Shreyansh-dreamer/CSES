#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    vector<vector<int>>pref(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;

        for(int j=1;j<=n;j++)
            pref[i][j]=(s[j-1]=='*');
    }

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++)
            pref[i][j]+=pref[i-1][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            pref[i][j]+=pref[i][j-1];
    }

    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;

        cout<<pref[y2][x2]
            -pref[y1-1][x2]
            -pref[y2][x1-1]
            +pref[y1-1][x1-1]<<'\n';
    }

    return 0;
}