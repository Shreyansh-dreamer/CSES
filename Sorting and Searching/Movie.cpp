#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int,int> &x, pair<int,int> &y) {
        return x.second < y.second;
    });

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        int l = 0, r = i - 1, pos = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (a[mid].second <= a[i].first) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (pos != -1) {
            dp[i] = max(dp[i], dp[pos] + 1);
        }

        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}