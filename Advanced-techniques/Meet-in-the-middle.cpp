#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> mp;
long long ans = 0, x;
vector<long long> a;

void gen1(int ind, int end, long long sum) {
    if (sum > x)
        return;

    if (ind == end) {
        mp[sum]++;
        return;
    }

    gen1(ind + 1, end, sum);
    gen1(ind + 1, end, sum + a[ind]);
}

void gen2(int ind, int end, long long sum) {
    if (sum > x)
        return;

    if (ind == end) {
        auto it = mp.find(x - sum);
        if (it != mp.end())
            ans += it->second;
        return;
    }

    gen2(ind + 1, end, sum);
    gen2(ind + 1, end, sum + a[ind]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> x;

    a.resize(n);

    for (auto &v : a)
        cin >> v;

    int mid = n / 2;

    mp.reserve(1 << (mid + 1));
    mp.max_load_factor(0.7);

    gen1(0, mid, 0);
    gen2(mid, n, 0);

    cout << ans << '\n';
}