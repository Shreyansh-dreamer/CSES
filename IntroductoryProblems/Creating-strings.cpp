#include <bits/stdc++.h>
using namespace std;

string s, temp;
vector<string> ans;
int freq[26];

void solve() {
    if (temp.size() == s.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freq[i]--;
            temp.push_back(char('a' + i));

            solve();

            temp.pop_back();
            freq[i]++;
        }
    }
}

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }

    solve();

    cout << ans.size() << endl;
    for (auto &it : ans) {
        cout << it << endl;
    }

    return 0;
}