ps link: https://codeforces.com/problemset/problem/1513/B

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

vector<long long> fact(MAX);

// Precompute factorials modulo MOD
void compute_factorials() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_factorials();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> u(n);
        int x = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            x = min(x, u[i]);
        }

        bool flag = false;
        long long c = 0;
        for (int i = 0; i < n; i++) {
            if (u[i] == x) c++;
            if ((u[i] & x) < x) flag = true;  // can also take  (u[i] & x) != x
        }

        if (flag || c <= 1) {
            cout << 0 << '\n';
        } else {
            long long result = (((c * (c - 1)) % MOD) * fact[n - 2]) % MOD;
            cout << result << '\n';
        }
    }

    return 0;
}

Time Complexity per test case: O(n)
