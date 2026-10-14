#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        a[0][i] = i;
        a[i][0] = i;
        a[i][i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] != -1) continue;

            unordered_set<int> mpp;

            for (int k = 0; k < j; k++) {
                mpp.insert(a[i][k]);
            }

            for (int k = 0; k < i; k++) {
                mpp.insert(a[k][j]);
            }

            int x = 0;
            while (mpp.count(x)) x++;

            a[i][j] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}