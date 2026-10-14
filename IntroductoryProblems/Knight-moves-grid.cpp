#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<vector<int>> ans(n, vector<int>(n, 0));

    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;

    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    pq.push({0, 0, 0});
    vis[0][0] = 1;

    while (!pq.empty()) {
        auto [cnt, r, c] = pq.top();
        pq.pop();

        ans[r][c] = cnt;

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                pq.push({cnt + 1, nr, nc});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}