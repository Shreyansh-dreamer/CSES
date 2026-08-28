//a little different from part 1, here instead of actually multiplying, 
//we are taking the minimum of the sum of the two elements, and instead of 0, we are using INF to represent no path.
/// normal multiplication
//I[i][i] = 1;

// min-plus multiplication
//I[i][i] = 0;
#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

vector<vector<long long>> multiply(vector<vector<long long>>& A,
                                   vector<vector<long long>>& B) {
    int n = A.size();

    vector<vector<long long>> C(n, vector<long long>(n, INF));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            if(A[i][k] == INF) continue;

            for(int j = 0; j < n; j++) {
                if(B[k][j] == INF) continue;

                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }

    return C;
}

vector<vector<long long>> power(vector<vector<long long>>& A, long long k) {
    int n = A.size();

    if(k == 0) {
        vector<vector<long long>> I(n, vector<long long>(n, INF));

        for(int i = 0; i < n; i++)
            I[i][i] = 0;

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

    vector<vector<long long>> mat(n, vector<long long>(n, INF));

    for(int i = 0; i < m; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        a--;
        b--;

        mat[a][b] = min(mat[a][b], c);
    }

    vector<vector<long long>> ans = power(mat, k);

    if(ans[0][n - 1] == INF)
        cout << -1 << '\n';
    else
        cout << ans[0][n - 1] << '\n';
}