#include <bits/stdc++.h>
using namespace std;

vector<long long> seg, lazy, a, pref;

void build(int ind, int l, int r) {
    if(l == r) {
        seg[ind] = pref[l];
        return;
    }

    int mid = l + (r - l) / 2;

    build(2 * ind + 1, l, mid);
    build(2 * ind + 2, mid + 1, r);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void updateRange(int start, int end, int ind, int l, int r, long long val) {
    if(lazy[ind] != 0) {
        seg[ind] += lazy[ind];

        if(l != r) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if(l > end || r < start)
        return;

    if(l >= start && r <= end) {
        seg[ind] += val;

        if(l != r) {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }

        return;
    }

    int mid = l + (r - l) / 2;

    updateRange(start, end, 2 * ind + 1, l, mid, val);
    updateRange(start, end, 2 * ind + 2, mid + 1, r, val);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

long long query(int start, int end, int ind, int l, int r) {
    if(lazy[ind] != 0) {
        seg[ind] += lazy[ind];

        if(l != r) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    if(l > end || r < start)
        return LLONG_MIN;

    if(l >= start && r <= end)
        return seg[ind];

    int mid = l + (r - l) / 2;

    return max(
        query(start, end, 2 * ind + 1, l, mid),
        query(start, end, 2 * ind + 2, mid + 1, r)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    pref.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] + (i ? pref[i - 1] : 0);
    }

    seg.resize(4 * n);
    lazy.resize(4 * n);

    build(0, 0, n - 1);

    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1) {
            x--;

            long long diff = y - a[x];
            a[x] = y;

            updateRange(x, n - 1, 0, 0, n - 1, diff);
        }
        else {
            x--;
            y--;

            long long mx = query(x, y, 0, 0, n - 1);

            long long before = (x == 0 ? 0 : query(x - 1, x - 1, 0, 0, n - 1));

            cout << max(0LL, mx - before) << '\n';
        }
    }
}