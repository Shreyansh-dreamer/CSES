#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;
const int N = 200005;

long long seg1[4 * N], seg2[4 * N];
long long a[N];

void build1(int node, int l, int r) {
    if(l == r) {
        seg1[node] = a[l] - l;
        return;
    }
    int mid = (l + r) / 2;
    build1(node * 2, l, mid);
    build1(node * 2 + 1, mid + 1, r);
    seg1[node] = min(seg1[node * 2], seg1[node * 2 + 1]);
}

void build2(int node, int l, int r) {
    if(l == r) {
        seg2[node] = a[l] + l;
        return;
    }
    int mid = (l + r) / 2;
    build2(node * 2, l, mid);
    build2(node * 2 + 1, mid + 1, r);
    seg2[node] = min(seg2[node * 2], seg2[node * 2 + 1]);
}

void update1(int node, int l, int r, int idx, long long val) {
    if(l == r) {
        seg1[node] = val - idx;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid)update1(node * 2, l, mid, idx, val);
    else update1(node * 2 + 1, mid + 1, r, idx, val);
    seg1[node] = min(seg1[node * 2], seg1[node * 2 + 1]);
}

void update2(int node, int l, int r, int idx, long long val) {
    if(l == r) {
        seg2[node] = val + idx;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid)update2(node * 2, l, mid, idx, val);
    else update2(node * 2 + 1, mid + 1, r, idx, val);
    seg2[node] = min(seg2[node * 2], seg2[node * 2 + 1]);
}

long long query1(int node, int l, int r, int ql, int qr) {
    if(ql > r || qr < l)
        return INF;
    if(ql <= l && r <= qr)
        return seg1[node];
    int mid = (l + r) / 2;
    return min(
        query1(node * 2, l, mid, ql, qr),
        query1(node * 2 + 1, mid + 1, r, ql, qr)
    );
}

long long query2(int node, int l, int r, int ql, int qr) {
    if(ql > r || qr < l)
        return INF;
    if(ql <= l && r <= qr)
        return seg2[node];
    int mid = (l + r) / 2;
    return min(
        query2(node * 2, l, mid, ql, qr),
        query2(node * 2 + 1, mid + 1, r, ql, qr)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build1(1, 1, n);
    build2(1, 1, n);
    while(q--) {
        int type, k;
        cin >> type >> k;
        if(type == 1) {
            long long x;
            cin >> x;
            a[k] = x;
            update1(1, 1, n, k, x);
            update2(1, 1, n, k, x);
        }
        else {
            long long left = query1(1, 1, n, 1, k) + k;
            long long right = query2(1, 1, n, k, n) - k;
            cout << min(left, right) << '\n';
        }
    }
}