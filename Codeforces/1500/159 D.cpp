ps link: https://codeforces.com/problemset/problem/159/D

#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pre(n + 1, 0); // pre[i] = total palindromic substrings in s[0..i-1]

    // Count palindromic substrings ending at each position
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j <= i; j++) {
            if (is_palindrome(s, i - j, i)) count++;
        }
        pre[i + 1] = pre[i] + count;
    }

    // Now count valid non-overlapping palindrome pairs
    long long ans = 0;
    for (int i = 0; i < n; i++) {         // start of 2nd palindrome
        for (int j = i; j < n; j++) {     // end of 2nd palindrome
            if (is_palindrome(s, i, j)) {
                ans += pre[i]; // all palindromes ending before i
            }
        }
    }

    cout << ans << endl;
    return 0;
}

Time Complexity	O(n²)
Space Complexity	O(n²)



#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // 1-based indexing
    s = " " + s; // pad to make s[1..n]

    // dp_pal[i][j] = true if s[i..j] is a palindrome
    vector<vector<bool>> dp_pal(n + 1, vector<bool>(n + 1, false));

    // Precompute all palindromic substrings
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || dp_pal[i + 1][j - 1])) {
                dp_pal[i][j] = true;
            }
        }
    }

    vector<long long> sum(n + 1, 0); // sum[i] = #palindromes in s[1..i]
    vector<long long> dp(n + 1, 0);  // dp[i] = #valid non-overlapping palindrome pairs in s[1..i]

    for (int i = 1; i <= n; ++i) {
        // Count all palindromes ending at i
        for (int j = 1; j <= i; ++j) {
            if (dp_pal[j][i]) {
                sum[i] += 1;
                dp[i] += sum[j - 1]; // all palindromes before j can pair with [j..i]
            }
        }
        sum[i] += sum[i - 1]; // carry forward total count
        dp[i] += dp[i - 1];   // carry forward total answer
    }

    cout << dp[n] << endl;
    return 0;
}

TC - O(N^2)
SC - O(N^2)
