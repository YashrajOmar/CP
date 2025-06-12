ps link : https://codeforces.com/problemset/problem/2114/E

#include <bits/stdc++.h>
using namespace std;

// DFS to build parent array
void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &par) {
    par[node] = parent;
    for (int nei : adj[node]) {
        if (nei != parent) {
            dfs(nei, node, adj, par);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Read node values (1-based indexing)
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // Read edges and build adjacency list
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Build parent array using DFS
        vector<int> par(n + 1, -1);
        dfs(1, -1, adj, par);  // Assume node 1 is the root

        vector<long long> dp(n + 1, 0);
        vector<int> vis(n + 1, -1);  // Visited array for BFS traversal
        queue<int> q;
        q.push(1);

        // BFS traversal to fill dp[i]
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            vis[i] = 0;

            for (auto nei : adj[i]) {
                if (vis[nei] == -1) {
                    q.push(nei);
                }
            }

            dp[i] = a[i]; // Initialize with current node's value
            long long x = a[i];

            if (par[i] != -1) {
                x -= a[par[i]];  // Subtract parent's value
                if (par[par[i]] != -1) {
                    x += dp[par[par[i]]];  // Add grandparent's dp value
                }
            }

            dp[i] = max(dp[i], x);  // Take max of current or modified value
        }

        // Output the dp array
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}

TC - O(N)
SC - O(N)
