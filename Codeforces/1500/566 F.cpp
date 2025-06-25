ps link: https://codeforces.com/problemset/problem/566/F

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int max_clique = 1;

    // Iterate over input elements
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        dp[x]++;  // At least length 1

        // Propagate to multiples
        for (int m = 2 * x; m < MAX; m += x) {
            dp[m] = max(dp[m], dp[x]);
        }

        max_clique = max(max_clique, dp[x]);
    }

    cout << max_clique << '\n';
    return 0;
}

TC - O(N log M)
SC - O(N)


#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(MAX, 0);
    vector<int> dp(MAX, 0);
    vector<bool> exists(MAX, false);

    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        exists[a[i]] = true;
        max_val = max(max_val, a[i]);
    }

    int ans = 0;

    for (int x = 1; x <= max_val; ++x) {
        if (!exists[x]) continue;

        dp[x] += freq[x];

        for (int y = 2 * x; y <= max_val; y += x) {
            if (exists[y]) {
                dp[y] = max(dp[y], dp[x]);
            }
        }

        ans = max(ans, dp[x]);
    }

    cout << ans << '\n';
    return 0;
}
