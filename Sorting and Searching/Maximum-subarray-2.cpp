#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long sum = 0, ans = LLONG_MIN;
    int l = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(i - l + 1 >= a) ans = max(ans, sum);

        if(i - l + 1 == b) {
            sum -= arr[l];
            l++;
        }
    }

    cout << ans << endl;
}