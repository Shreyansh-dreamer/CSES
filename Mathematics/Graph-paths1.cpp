#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>>& A,
                                   vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> power(vector<vector<long long>>& A, long long k) {
    int n = A.size();

    if(k == 0) {
        vector<vector<long long>> I(n, vector<long long>(n));
        for(int i = 0; i < n; i++)
            I[i][i] = 1;
        return I;
    }

    if(k % 2 == 0) {
        vector<vector<long long>> half = power(A, k / 2);
        return multiply(half, half);
    }

    vector<vector<long long>> half = power(A, k / 2);
    vector<vector<long long>> res = multiply(half, half);

    return multiply(res, A);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<vector<long long>> mat(n, vector<long long>(n));

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mat[a][b]++;
    }

    vector<vector<long long>> res = power(mat, k);

    cout << res[0][n - 1] << '\n';
}