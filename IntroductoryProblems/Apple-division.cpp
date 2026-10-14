#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = LLONG_MAX;
vector<long long> p;

void solve(int ind, long long sum1, long long sum2) {
    if (ind == n) {
        ans = min(ans, abs(sum1 - sum2));
        return;
    }

    solve(ind + 1, sum1 + p[ind], sum2);
    solve(ind + 1, sum1, sum2 + p[ind]);
}

int main() {
    cin >> n;
    p.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    solve(0, 0, 0);

    cout << ans << endl;
    return 0;
}