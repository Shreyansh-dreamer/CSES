#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while(n--){
        int x;
        cin>>x;

        int ans=0;

        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(i==x/i)
                    ans++;
                else
                    ans+=2;
            }
        }

        cout<<ans<<'\n';
    }
}