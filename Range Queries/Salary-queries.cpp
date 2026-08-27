#include <bits/stdc++.h>
using namespace std;

vector<long long> seg;
int n;

void update(int pos, int val, int ind, int l, int r) {
    if (l == r) {
        seg[ind] += val;
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(pos, val, 2 * ind + 1, l, mid);
    else
        update(pos, val, 2 * ind + 2, mid + 1, r);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

long long find(int ql, int qr, int ind, int l, int r) {
    if (l > qr || r < ql)
        return 0;

    if (ql <= l && r <= qr)
        return seg[ind];

    int mid = (l + r) / 2;

    return find(ql, qr, 2 * ind + 1, l, mid) +
           find(ql, qr, 2 * ind + 2, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    vector<long long> a(n);
    vector<long long> vals;

    for (auto &x : a) {
        cin >> x;
        vals.push_back(x);
    }

    vector<tuple<char,int,long long>> queries(q);

    for (auto &[ch, x, y] : queries) {
        cin >> ch >> x >> y;
        if (ch == '!')
            vals.push_back(y);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int sz = vals.size();
    seg.resize(4 * sz);

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        update(pos, 1, 0, 0, sz - 1);
    }

    for (auto [ch, x, y] : queries) {
        if (ch == '!') {
            int oldPos = lower_bound(vals.begin(), vals.end(), a[x - 1]) - vals.begin();
            int newPos = lower_bound(vals.begin(), vals.end(), y) - vals.begin();

            update(oldPos, -1, 0, 0, sz - 1);
            update(newPos, 1, 0, 0, sz - 1);

            a[x - 1] = y;
        }
        else {
            int l = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            int r = upper_bound(vals.begin(), vals.end(), y) - vals.begin() - 1;

            cout << find(l, r, 0, 0, sz - 1) << '\n';
        }
    }
}