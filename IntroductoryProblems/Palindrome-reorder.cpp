#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'A']++;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) cnt++;
    }

    if (cnt > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string left = "", mid = "";

    for (int i = 0; i < 26; i++) {
        left += string(freq[i] / 2, char('A' + i));

        if (freq[i] % 2) {
            mid = string(1, char('A' + i));
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left + mid + right << endl;

    return 0;
}