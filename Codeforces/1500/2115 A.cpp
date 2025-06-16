ps link: https://codeforces.com/problemset/problem/2115/A

#include <bits/stdc++.h>
using namespace std;

const int MAXA = 5001;
int gcd_table[MAXA][MAXA];

void precompute_gcd() {
    for (int i = 0; i < MAXA; i++) {
        for (int j = 0; j < MAXA; j++) {
            gcd_table[i][j] = __gcd(i, j); // precomputed GCD table: g[x][y] = gcd(x, y)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_gcd();  // preprocess all gcd pairs

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int g = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            g = __gcd(g, a[i]);
        }

        int cnt_equal_g = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == g) cnt_equal_g++;
        }

        if (cnt_equal_g > 0) {
            cout << n - cnt_equal_g << '\n';
            continue;
        }

        // DP part
        vector<int> f(MAXA, INT_MAX);
        for (int i = 0; i < n; i++) {
            f[a[i]] = 0;              ///min steps needed to raech make every value = a[i]
                                //DP array storing minimum operations for each GCD state.
        }
int MAXA = *max_element(a.begin(), a.end()) + 1;
        for (int x = MAXA - 1; x >= 1; x--) {
            if (f[x] == INT_MAX) continue;
            for (int i = 0; i < n; i++) {
                int y = gcd_table[x][a[i]];
                f[y] = min(f[y], max(f[x], f[a[i]]) + 1);  // f[y] = min(f[y], f[x] + 1);
            }
        }

        cout << n - 2 + f[g] << '\n';
    }
}

TC - O(MaxA * N)
