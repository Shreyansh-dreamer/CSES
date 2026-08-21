#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<int> v;

    for(int x:a){
        int l=0,r=v.size();

        while(l<r){
            int m=(l+r)/2;

            if(v[m]>=x)
                r=m;
            else
                l=m+1;
        }

        if(l==v.size())
            v.push_back(x);
        else
            v[l]=x;
    }

    cout<<v.size()<<endl;

    return 0;
}