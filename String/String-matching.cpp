#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,p;
    cin>>s>>p;

    int n=s.size(),m=p.size();

    vector<int> lps(m,0);

    for(int i=1,len=0;i<m;){
        if(p[i]==p[len]){
            lps[i]=++len;
            i++;
        }
        else if(len)
            len=lps[len-1];
        else{
            lps[i]=0;
            i++;
        }
    }

    int ans=0;

    for(int i=0,j=0;i<n;){
        if(s[i]==p[j]){
            i++;
            j++;

            if(j==m){
                ans++;
                j=lps[j-1];
            }
        }
        else if(j)
            j=lps[j-1];
        else
            i++;
    }

    cout<<ans<<'\n';

    return 0;
}