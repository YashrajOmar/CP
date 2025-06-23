ps link: https://codeforces.com/problemset/problem/2050/E



#include <iostream>
#include <algorithm>

static const int inf = 1e9;

void solve() {
    std::string a, b, res;
    std::cin >> a >> b >> res;
    int n = (int) a.size(), m = (int) b.size();
    int dp[n + 1][m + 1];
    std::fill(&dp[0][0], &dp[0][0] + (n + 1) * (m + 1), inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = dp[i][0] + (a[i] != res[i]);
    }
    for (int j = 0; j < m; j++) {
        dp[0][j + 1] = dp[0][j] + (b[j] != res[j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = std::min(dp[i - 1][j] + (a[i - 1] != res[i + j - 1]),
                                dp[i][j - 1] + (b[j - 1] != res[i + j - 1]));
        }
    }
    std::cout << dp[n][m] << std::endl;
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        solve();
    }
}



#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    
                    dp[i][j] = dp[i][j - 1];
                    if((j > 0 && b[j - 1] == c[i + j - 1])) dp[i][j]++;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                    if(i > 0 && a[i - 1] == c[i + j - 1]) dp[i][j]++;
                } else {
                    dp[i][j] = max(dp[i - 1][j] + (a[i - 1] == c[i + j - 1]), dp[i][j - 1] + (b[j - 1] == c[i + j - 1]));
                }
            }
        }
      //  for(int i = 0; i <= n; i++){
      //       for(int j = 0; j <= m; j++){
      //           cout<<dp[i][j]<<" ";
      //       } cout<<endl;
      //  }
        cout<<m+n-dp[n][m]<<endl;
    }
}

TC - O(N*M)
SC - O(N*M)

  
