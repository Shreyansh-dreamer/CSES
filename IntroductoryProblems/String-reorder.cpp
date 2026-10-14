#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'A']++;
    }

    int n = s.size();
    for (int i = 0; i < 26; i++) {
        if (freq[i] > (n + 1) / 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    string ans = "";
    char prev = '#';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0 || char('A' + j) == prev) continue;

            freq[j]--;

            int rem = n - i - 1;
            bool ok = true;

            for (int k = 0; k < 26; k++) {
                if (freq[k] > (rem + 1) / 2) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans += char('A' + j);
                prev = char('A' + j);
                break;
            }

            freq[j]++;
        }
    }

    cout << ans << endl;
    return 0;
}