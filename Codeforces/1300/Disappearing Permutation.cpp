problem link : https://codeforces.com/problemset/problem/2086/C


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), d(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            cin >> d[i];
        }

        vector<int> vis(n + 1, 0);
        map<int, int> cycleSize;

        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                int start = i;
                int count = 0;
                int cur = i;
                while (vis[cur] == 0) {
                    vis[cur] = start;
                    cur = a[cur];
                    count++;
                }
                cycleSize[start] = count;
            }
        }

        // Optional: Print vis and cycles
        // for (int i = 1; i <= n; ++i) cout << vis[i] << " ";
        // cout << endl;
        // for (auto [x, y] : cycleSize) cout << x << ":" << y << " ";
        // cout << endl;

        vector<int> got(n + 1, 0); // To check if a cycle is already processed
        vector<int> ans;
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            int cycle_id = vis[d[i]];
            if (got[cycle_id]) {
                ans.push_back(sum);
            } else {
                sum += cycleSize[cycle_id];
                got[cycle_id] = 1;
                ans.push_back(sum);
            }
        }

        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
}


TC - O(N)
SC - O(N)
