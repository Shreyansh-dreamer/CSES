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

void update(int ind, int l, int r, int k, long long x) {
    if (l == r) {
        segSum[ind] = x;
        pref[ind] = suff[ind] = best[ind] = max(0LL, x);
        return;
    }

    int mid = l + (r - l) / 2;

    if (k <= mid)
        update(2 * ind + 1, l, mid, k, x);
    else
        update(2 * ind + 2, mid + 1, r, k, x);

    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    segSum[ind] = segSum[left] + segSum[right];
    pref[ind] = max(pref[left], segSum[left] + pref[right]);
    suff[ind] = max(suff[right], segSum[right] + suff[left]);
    best[ind] = max({best[left], best[right], suff[left] + pref[right]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    segSum.resize(4 * n);
    pref.resize(4 * n);
    suff.resize(4 * n);
    best.resize(4 * n);

    build(0, 0, n - 1, arr);

    while (m--) {
        int k;
        long long x;
        cin >> k >> x;
        update(0, 0, n - 1, k - 1, x);
        cout << best[0] << endl;
    }
}