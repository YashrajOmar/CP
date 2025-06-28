 BFS-based Bipartite Check and Vertex Cover Extraction


#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj, int n, vector<int>& color) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Not bipartite
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);

    if (isBipartite(adj, n, color)) {
        cout << "Graph is bipartite.\n";
        vector<int> part0, part1;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) part0.push_back(i);
            else part1.push_back(i);
        }

        cout << "Vertex Cover 1: ";
        for (int v : part0) cout << v << " ";
        cout << "\n";

        cout << "Vertex Cover 2: ";
        for (int v : part1) cout << v << " ";
        cout << "\n";
    } else {
        cout << "Graph is not bipartite, so it can't be split into two vertex covers.\n";
    }

    return 0;
}




DFS-based Bipartite Check and Vertex Cover Extraction


#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int c, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = c;

    for (int v : adj[u]) {
        if (color[v] == -1) {
            if (!dfs(v, 1 - c, adj, color)) return false;
        } else if (color[v] == color[u]) {
            return false; // Not bipartite
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    bool isBipartite = true;

    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            if (!dfs(i, 0, adj, color)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite) {
        cout << "Graph is bipartite.\n";
        vector<int> part0, part1;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) part0.push_back(i);
            else part1.push_back(i);
        }

        cout << "Vertex Cover 1: ";
        for (int v : part0) cout << v << " ";
        cout << "\n";

        cout << "Vertex Cover 2: ";
        for (int v : part1) cout << v << " ";
        cout << "\n";
    } else {
        cout << "Graph is not bipartite, so it can't be split into two vertex covers.\n";
    }

    return 0;
}


Time Complexity: O(n + m)
Space Complexity: O(n + m)
