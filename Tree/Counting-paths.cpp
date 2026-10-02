//The easiest way to understand it is to forget the formula first and see what we are trying to make happen.
// Suppose one query asks for the path:
// 2 → 5
// and the tree is:
//         1
//        / \
//       2   3
//          / \
//         4   5
// The path is:
// 2 → 1 → 3 → 5
// We want every node on this path to eventually get +1.
// The trick
// Put:
// diff[2] += 1
// diff[5] += 1
//diff[lca(2,5)] -= 1
//diff[parent(lca(2,5))] -= 1
// Why?
// Because later, when we propagate values from children to parents, the +1 at 2 travels upward:
// 2: +1
// ↓
// 1: +1
// And the +1 at 5 travels upward:
// 5: +1
// ↓
// 3: +1
// ↓
// 1: +1
// So now:
//         1 = 2
//        / \
//    2 = 1  3 = 1
//             \
//             5 = 1
// But there is a problem: node 1 got 2, while we want it to count this path only once.
// So we need to cancel one copy at the LCA.
// The LCA of 2 and 5 is 1.
// Therefore:
// diff[1] -= 1
// Now:
//         1 = 1
//        / \
//    2 = 1  3 = 1
//             \
//             5 = 1
// Exactly what we want.

#include<bits/stdc++.h>
using namespace std;

const int N=200005;
const int LOG=20;

vector<int> adj[N];
int up[N][LOG];
int depth[N];
long long diff[N];

void dfs(int u,int p){
    up[u][0]=p;

    for(int j=1;j<LOG;j++)
        up[u][j]=up[up[u][j-1]][j-1];

    for(int v:adj[u]){
        if(v==p)continue;

        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a,b);

    int d=depth[a]-depth[b];

    for(int j=LOG-1;j>=0;j--){
        if(d&(1<<j))
            a=up[a][j];
    }

    if(a==b)return a;

    for(int j=LOG-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }

    return up[a][0];
}

void dfs2(int u,int p){
    for(int v:adj[u]){
        if(v==p)continue;

        dfs2(v,u);
        diff[u]+=diff[v];
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        int l=lca(a,b);

        diff[a]++;
        diff[b]++;
        diff[l]--;

        if(l!=1)
            diff[up[l][0]]--;
    }

    dfs2(1,1);

    for(int i=1;i<=n;i++)
        cout<<diff[i]<<" ";

    cout<<endl;
}