#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>>& A,
                                   vector<vector<long long>>& B) {
    vector<vector<long long>> C(2, vector<long long>(2));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> power(vector<vector<long long>>& A, long long n) {
    if(n == 0)
        return {{1, 0}, {0, 1}};

    vector<vector<long long>> half = power(A, n / 2);
    vector<vector<long long>> res = multiply(half, half);

    if(n % 2)
        res = multiply(res, A);

    return res;
}

int main() {
    long long n;
    cin >> n;

    vector<vector<long long>> mat = {
        {1, 1},
        {1, 0}
    };

    auto ans = power(mat, n);

    cout << ans[0][1] << '\n';
}