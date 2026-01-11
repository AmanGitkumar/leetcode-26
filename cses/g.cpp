#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;
int n;

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &a, const Matrix &b) {
    Matrix c(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (a[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

Matrix matrix_power(Matrix base, long long exp) {
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1;

    while (exp) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    int m;
    long long k;
    cin >> n >> m >> k;

    Matrix adj(n, vector<long long>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1][b - 1]++;
    }

    Matrix res = matrix_power(adj, k);
    cout << res[0][n - 1] << "\n";
}
