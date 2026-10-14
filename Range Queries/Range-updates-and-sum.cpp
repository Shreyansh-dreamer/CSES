#include <bits/stdc++.h>
using namespace std;

vector<long long> seg, lazy, lazyset;
int n;

void build(int ind, int l, int r, vector<int>& arr) {
    if (l == r) {
        seg[ind] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * ind + 1, l, mid, arr);
    build(2 * ind + 2, mid + 1, r, arr);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void push(int ind, int l, int r) {
    if (lazyset[ind] != 0) {
        seg[ind] = 1LL * (r - l + 1) * lazyset[ind];

        if (l != r) {
            lazyset[2 * ind + 1] = lazyset[ind];
            lazyset[2 * ind + 2] = lazyset[ind];
            lazy[2 * ind + 1] = 0;
            lazy[2 * ind + 2] = 0;
        }

        lazy[ind] = 0;
        lazyset[ind] = 0;
    }

    if (lazy[ind] != 0) {
        seg[ind] += 1LL * (r - l + 1) * lazy[ind];

        if (l != r) {
            int left = 2 * ind + 1;
            int right = 2 * ind + 2;

            if (lazyset[left] != 0)
                lazyset[left] += lazy[ind];
            else
                lazy[left] += lazy[ind];

            if (lazyset[right] != 0)
                lazyset[right] += lazy[ind];
            else
                lazy[right] += lazy[ind];
        }

        lazy[ind] = 0;
    }
}

void updateRange(int start, int end, int ind, int l, int r, int val) {
    push(ind, l, r);

    if (l > end || r < start || l > r)
        return;

    if (l >= start && r <= end) {
        seg[ind] += 1LL * (r - l + 1) * val;

        if (l != r) {
            int left = 2 * ind + 1;
            int right = 2 * ind + 2;

            if (lazyset[left] != 0)
                lazyset[left] += val;
            else
                lazy[left] += val;

            if (lazyset[right] != 0)
                lazyset[right] += val;
            else
                lazy[right] += val;
        }
        return;
    }

    int mid = l + (r - l) / 2;
    updateRange(start, end, 2 * ind + 1, l, mid, val);
    updateRange(start, end, 2 * ind + 2, mid + 1, r, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void updateSet(int start, int end, int ind, int l, int r, int val) {
    push(ind, l, r);

    if (l > end || r < start || l > r)
        return;

    if (l >= start && r <= end) {
        seg[ind] = 1LL * (r - l + 1) * val;

        if (l != r) {
            lazyset[2 * ind + 1] = val;
            lazyset[2 * ind + 2] = val;
            lazy[2 * ind + 1] = 0;
            lazy[2 * ind + 2] = 0;
        }
        return;
    }

    int mid = l + (r - l) / 2;
    updateSet(start, end, 2 * ind + 1, l, mid, val);
    updateSet(start, end, 2 * ind + 2, mid + 1, r, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

long long query(int start, int end, int ind, int l, int r) {
    push(ind, l, r);

    if (l > end || r < start || l > r)
        return 0;

    if (l >= start && r <= end)
        return seg[ind];

    int mid = l + (r - l) / 2;
    return query(start, end, 2 * ind + 1, l, mid) +
           query(start, end, 2 * ind + 2, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    seg.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    lazyset.resize(4 * n, 0);

    build(0, 0, n - 1, arr);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--;
        b--;

        if (type == 1) {
            int x;
            cin >> x;
            updateRange(a, b, 0, 0, n - 1, x);
        }
        else if (type == 2) {
            int x;
            cin >> x;
            updateSet(a, b, 0, 0, n - 1, x);
        }
        else {
            cout << query(a, b, 0, 0, n - 1) << endl;
        }
    }
}