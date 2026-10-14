#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    while (n > 0) {
        n /= 5;
        ans += n;
    }

    cout << ans << endl;
    return 0;
}