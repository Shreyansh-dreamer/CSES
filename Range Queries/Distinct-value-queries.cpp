#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
        queries[i][2] = i;
    }

    int block = sqrt(n);

    sort(queries.begin(), queries.end(),
         [block](const vector<int>& x, const vector<int>& y) {
             if (x[0] / block != y[0] / block)
                 return x[0] / block < y[0] / block;
             return x[1] < y[1];
         });

    vector<int> freq(v.size(), 0);
    vector<int> ans(q);

    int l = 0, r = -1;
    int distinct = 0;

    for (int i = 0; i < q; i++) {
        int ql = queries[i][0];
        int qr = queries[i][1];

        while (l > ql) {
            l--;
            if (freq[a[l]] == 0)
                distinct++;
            freq[a[l]]++;
        }

        while (r < qr) {
            r++;
            if (freq[a[r]] == 0)
                distinct++;
            freq[a[r]]++;
        }

        while (l < ql) {
            freq[a[l]]--;
            if (freq[a[l]] == 0)
                distinct--;
            l++;
        }

        while (r > qr) {
            freq[a[r]]--;
            if (freq[a[r]] == 0)
                distinct--;
            r--;
        }

        ans[queries[i][2]] = distinct;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}