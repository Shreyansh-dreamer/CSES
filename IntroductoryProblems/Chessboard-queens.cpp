#include <bits/stdc++.h>
using namespace std;

vector<string> grid(8);

int backtrack(int row, vector<vector<bool>> mat) {
    if (row == 8) return 1;

    int ans = 0;

    for (int j = 0; j < 8; j++) {
        if (grid[row][j] == '.' && !mat[row][j]) {
            vector<vector<bool>> temp = mat;

            for (int k = 0; k < 8; k++) {
                temp[row][k] = true;
                temp[k][j] = true;

                if (row + k < 8 && j + k < 8)
                    temp[row + k][j + k] = true;

                if (row + k < 8 && j - k >= 0)
                    temp[row + k][j - k] = true;

                if (row - k >= 0 && j + k < 8)
                    temp[row - k][j + k] = true;

                if (row - k >= 0 && j - k >= 0)
                    temp[row - k][j - k] = true;
            }

            ans += backtrack(row + 1, temp);
        }
    }

    return ans;
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> mat(8, vector<bool>(8, false));

    cout << backtrack(0, mat) << endl;
    return 0;
}