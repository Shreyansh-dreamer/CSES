#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long pwr(long long a, long long b) {
    if (b == 0) return 1;
    long long x = pwr(a, b / 2);
    x = x * x % mod;
    if (b % 2) x = x * a % mod;
    return x;
}

int main() {
    long long n;
    cin >> n;
    cout << pwr(2, n) << endl;
    return 0;
}