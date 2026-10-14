#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}