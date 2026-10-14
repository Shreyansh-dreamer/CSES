#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mpp;
vector<string> ans;

bool solve(string s, int n) {
    mpp[s] = true;
    ans.push_back(s);

    if (ans.size() == (1 << n)) return true;

    for (int i = 0; i < n; i++) {
        string temp = s;
        temp[i] = (temp[i] == '0' ? '1' : '0');

        if (!mpp[temp]) {
            if (solve(temp, n)) return true;
        }
    }

    mpp[s] = false;
    ans.pop_back();
    return false;
}

int main() {
    int n;
    cin >> n;

    solve(string(n, '0'), n);

    for (auto &it : ans) {
        cout << it << endl;
    }

    return 0;
}