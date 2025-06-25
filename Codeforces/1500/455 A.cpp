ps link: https://codeforces.com/problemset/problem/455/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]]++;
    }

    vector<ll> dp(1e5 + 5, 0);
    dp[1] = 1LL * m[1] * 1;

    for(int i = 2; i <= 1e5; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * m[i] * i);
    }

    cout << dp[1e5] << endl;
}


TC - O(1e5)
SC - O(N)
