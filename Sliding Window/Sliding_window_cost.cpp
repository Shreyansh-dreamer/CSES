#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    multiset<long long> L,R;
    long long sumL=0,sumR=0;

    auto balance = [&](){
        while(L.size()>R.size()+1){
            auto it=prev(L.end());
            long long x=*it;
            L.erase(it);
            R.insert(x);
            sumL-=x;
            sumR+=x;
        }

        while(R.size()>L.size()){
            auto it=R.begin();
            long long x=*it;
            R.erase(it);
            L.insert(x);
            sumR-=x;
            sumL+=x;
        }

        while(!L.empty()&&!R.empty()&&*prev(L.end())>*R.begin()){
            auto itL=prev(L.end());
            auto itR=R.begin();

            long long x=*itL,y=*itR;

            L.erase(itL);
            R.erase(itR);
            L.insert(y);
            R.insert(x);

            sumL+=y-x;
            sumR+=x-y;
        }
    };

    for(int i=0;i<k;i++){
        if(L.size()<=R.size()){
            L.insert(arr[i]);
            sumL+=arr[i];
        }
        else{
            R.insert(arr[i]);
            sumR+=arr[i];
        }
        balance();
    }

    for(int i=0;i+k<=n;i++){
        long long med=*prev(L.end());
        cout<<med*(long long)L.size()-sumL
              +sumR-med*(long long)R.size()<<" ";

        if(i+k<n){
            long long rem=arr[i];
            auto it=L.find(rem);

            if(it!=L.end()){
                L.erase(it);
                sumL-=rem;
            }
            else{
                it=R.find(rem);
                R.erase(it);
                sumR-=rem;
            }

            if(L.size()<=R.size()){
                L.insert(arr[i+k]);
                sumL+=arr[i+k];
            }
            else{
                R.insert(arr[i+k]);
                sumR+=arr[i+k];
            }

            balance();
        }
    }

    cout<<endl;
}