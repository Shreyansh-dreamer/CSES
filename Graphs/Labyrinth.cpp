#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &x:a) cin>>x;

    pair<int,int> st,en;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='A') st={i,j};
            if(a[i][j]=='B') en={i,j};
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>> prev(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>> move(n,vector<char>(m));

    queue<pair<int,int>> q;
    q.push(st);
    vis[st.first][st.second]=true;

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    char dir[]={'U','D','L','R'};

    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(a[nr][nc]=='#' || vis[nr][nc]) continue;

            vis[nr][nc]=true;
            prev[nr][nc]={r,c};
            move[nr][nc]=dir[k];

            q.push({nr,nc});
        }
    }

    if(!vis[en.first][en.second]){
        cout<<"NO\n";
        return 0;
    }

    string path;
    auto cur=en;

    while(cur!=st){
        path+=move[cur.first][cur.second];
        cur=prev[cur.first][cur.second];
    }

    reverse(path.begin(),path.end());

    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
}