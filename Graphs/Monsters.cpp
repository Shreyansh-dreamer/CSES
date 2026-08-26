#include <bits/stdc++.h>
using namespace std;

int n,m;

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
char dir[]={'U','D','L','R'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    vector<string> a(n);
    for(auto &x:a) cin>>x;

    vector<vector<int>> mon(n,vector<int>(m,1e9));
    vector<vector<int>> dist(n,vector<int>(m,-1));
    vector<vector<pair<int,int>>> prev(n,vector<pair<int,int>>(m,{-1,-1}));

    queue<pair<int,int>> q;

    pair<int,int> st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='M'){
                mon[i][j]=0;
                q.push({i,j});
            }
            else if(a[i][j]=='A'){
                st={i,j};
            }
        }
    }

    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(a[nr][nc]=='#') continue;
            if(mon[nr][nc]!=1e9) continue;

            mon[nr][nc]=mon[r][c]+1;
            q.push({nr,nc});
        }
    }

    q.push(st);
    dist[st.first][st.second]=0;

    pair<int,int> end={-1,-1};

    if(st.first==0 || st.first==n-1 || st.second==0 || st.second==m-1)
        end=st;

    while(!q.empty() && end.first==-1){
        auto [r,c]=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(a[nr][nc]=='#') continue;
            if(dist[nr][nc]!=-1) continue;

            if(dist[r][c]+1>=mon[nr][nc]) continue;

            dist[nr][nc]=dist[r][c]+1;
            prev[nr][nc]={r,c};

            if(nr==0 || nr==n-1 || nc==0 || nc==m-1){
                end={nr,nc};
                break;
            }

            q.push({nr,nc});
        }
    }

    if(end.first==-1){
        cout<<"NO\n";
        return 0;
    }

    string path;
    auto cur=end;

    while(cur!=st){
        auto p=prev[cur.first][cur.second];

        if(cur.first==p.first){
            if(cur.second>p.second) path+='R';
            else path+='L';
        }
        else{
            if(cur.first>p.first) path+='D';
            else path+='U';
        }

        cur=p;
    }

    reverse(path.begin(),path.end());

    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
}