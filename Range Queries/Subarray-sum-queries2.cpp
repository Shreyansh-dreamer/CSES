#include <bits/stdc++.h>
using namespace std;

vector<long long> segSum, pref, suff, best;
int n;

void build(int ind, int l, int r, vector<long long>& arr) {
    if (l == r) {
        segSum[ind] = arr[l];
        pref[ind] = suff[ind] = best[ind] = max(0LL, arr[l]);
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * ind + 1, l, mid, arr);
    build(2 * ind + 2, mid + 1, r, arr);

    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    segSum[ind] = segSum[left] + segSum[right];
    pref[ind] = max(pref[left], segSum[left] + pref[right]);
    suff[ind] = max(suff[right], segSum[right] + suff[left]);
    best[ind] = max({best[left], best[right], suff[left] + pref[right]});
}

vector<long long> query(int start, int end, int ind, int l, int r) {
    if (l > end || r < start)
        return {0, 0, 0, 0};

    if (l >= start && r <= end)
        return {segSum[ind], pref[ind], suff[ind], best[ind]};

    int mid = l + (r - l) / 2;

    vector<long long> left = query(start, end, 2 * ind + 1, l, mid);
    vector<long long> right = query(start, end, 2 * ind + 2, mid + 1, r);

    vector<long long> ans(4);
    ans[0] = left[0] + right[0];
    ans[1] = max(left[1], left[0] + right[1]);
    ans[2] = max(right[2], right[0] + left[2]);
    ans[3] = max({left[3], right[3], left[2] + right[1]});

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segSum.resize(4 * n);
    pref.resize(4 * n);
    suff.resize(4 * n);
    best.resize(4 * n);

    build(0, 0, n - 1, arr);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1, 0, 0, n - 1)[3] << endl;
    }
}