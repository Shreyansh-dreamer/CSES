/*
FLOW:

1. We have a tree, but a Segment Tree works on an array.

2. So first, flatten the tree using DFS.

3. When we enter a node u, give it a position:
      tin[u] = current position

   Example:
          1
         / \
        2   3
           / \
          4   5

   DFS order:
      1 -> 0
      2 -> 1
      3 -> 2
      4 -> 3
      5 -> 4

4. Now every subtree becomes a continuous range.

   Subtree of 3 = {3,4,5}
   Their positions = {2,3,4}

   So:
      tin[3]  = 2
      tout[3] = 4

   Therefore subtree of 3 is simply range [2,4].

5. We create a flat array:
      flat[tin[u]] = value[u]

   So the tree values are converted into an array according to DFS order.

6. Build a Segment Tree on this flat array.

7. Type 1: set node s's value to x.

   Node s is stored at position tin[s].

   So:
      segmentTree.update(tin[s], x)

8. Type 2: find sum of subtree of s.

   The subtree occupies:
      [tin[s], tout[s]]

   So:
      segmentTree.getSum(tin[s], tout[s])

9. Main idea to remember:

      TREE
        ↓
      DFS
        ↓
      tin[] and tout[]
        ↓
      FLAT ARRAY
        ↓
      SEGMENT TREE

   Update node:
      update(tin[node])

   Query subtree:
      query(tin[node], tout[node])
*/

#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<long long> seg;
    int n;

    SegmentTree(vector<long long>& arr){
        n=arr.size();
        seg.resize(4*n,0);
        build(0,0,n-1,arr);
    }

    void build(int ind,int l,int r,vector<long long>& arr){
        if(l==r){
            seg[ind]=arr[l];
            return;
        }

        int mid=l+(r-l)/2;

        build(2*ind+1,l,mid,arr);
        build(2*ind+2,mid+1,r,arr);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void update(int pos,long long val,int ind,int l,int r){
        if(l==r){
            seg[ind]=val;
            return;
        }

        int mid=l+(r-l)/2;

        if(pos<=mid)
            update(pos,val,2*ind+1,l,mid);
        else
            update(pos,val,2*ind+2,mid+1,r);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    long long query(int start,int end,int ind,int l,int r){
        if(r<start || l>end)
            return 0;

        if(start<=l && r<=end)
            return seg[ind];

        int mid=l+(r-l)/2;

        return query(start,end,2*ind+1,l,mid)
             +query(start,end,2*ind+2,mid+1,r);
    }

    void update(int pos,long long val){
        update(pos,val,0,0,n-1);
    }

    long long getSum(int l,int r){
        return query(l,r,0,0,n-1);
    }
};

const int N=200005;

vector<int> adj[N];

int tin[N];
int tout[N];
int timer=0;

void dfs(int u,int p){
    tin[u]=timer++;

    for(int v:adj[u]){
        if(v==p)
            continue;

        dfs(v,u);
    }

    tout[u]=timer-1;
}

int main(){
    int n,q;
    cin>>n>>q;

    vector<long long> value(n+1);

    for(int i=1;i<=n;i++)
        cin>>value[i];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Flatten the tree using DFS
    dfs(1,0);

    // Convert tree values into the flattened array
    vector<long long> flat(n);

    for(int i=1;i<=n;i++)
        flat[tin[i]]=value[i];

    // Build Segment Tree on flattened array
    SegmentTree st(flat);

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int s;
            long long x;

            cin>>s>>x;

            // Node s is stored at position tin[s]
            st.update(tin[s],x);
        }
        else{
            int s;
            cin>>s;

            // Entire subtree of s is [tin[s],tout[s]]
            cout<<st.getSum(tin[s],tout[s])<<endl;
        }
    }
}