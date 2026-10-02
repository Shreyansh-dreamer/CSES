#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis, parent, cycle;
bool found = false;

void dfs(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (found) return;

        if (vis[v] == 0) {
            parent[v] = u;
            dfs(v);
        }
        else if (vis[v] == 1) {
            cycle.push_back(v);

            int x = u;
            while (x != v) {
                cycle.push_back(x);
                x = parent[x];
            }

            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());

            found = true;
            return;
        }
    }

    vis[u] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (found) break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << cycle.size() << '\n';

    for (int x : cycle)
        cout << x << " ";

    cout << '\n';
}