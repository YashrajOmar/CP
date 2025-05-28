#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < n / 2; ++i){
            for(int j = 0; j < (n + 1) / 2; ++j){
                vector<char> vals;
                vals.push_back(a[i][j]);
                vals.push_back(a[j][n - 1 - i]);
                vals.push_back(a[n - 1 - i][n - 1 - j]);
                vals.push_back(a[n - 1 - j][i]);

                sort(vals.begin(), vals.end());
                char median = vals[3];  // second smallest (close to median)
                int cost = 0;
                for(char c : vals){
                    cost += abs(c - median);
                }
                ans += cost;
            }
        }

        cout << ans << endl;
    }
}
