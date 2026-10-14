
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 1LL * n * (n + 1) / 2;

    if (sum % 2) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    long long target = sum / 2;
    vector<int> a, b;

    for (int i = n; i >= 1; i--) {
        if (target >= i) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << a.size() << endl;
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << b.size() << endl;
    for (int x : b) cout << x << " ";
    cout << endl;

    return 0;
}
