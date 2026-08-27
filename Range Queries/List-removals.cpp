#include <bits/stdc++.h>
using namespace std;

vector<int> seg;
vector<long long> a;

void build(int ind, int l, int r) {
    if(l == r) {
        seg[ind] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind + 1, l, mid);
    build(2 * ind + 2, mid + 1, r);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int findKth(int k, int ind, int l, int r) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(seg[2 * ind + 1] >= k)
        return findKth(k, 2 * ind + 1, l, mid);
    return findKth(k - seg[2 * ind + 1], 2 * ind + 2, mid + 1, r);
}

void update(int pos, int ind, int l, int r) {
    if(l == r) {
        seg[ind] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
        update(pos, 2 * ind + 1, l, mid);
    else
        update(pos, 2 * ind + 2, mid + 1, r);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    for(auto &x : a) cin >> x;
    seg.resize(4 * n);
    build(0, 0, n - 1);
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int idx = findKth(p, 0, 0, n - 1);
        cout << a[idx] << " ";
        update(idx, 0, 0, n - 1);
    }
}