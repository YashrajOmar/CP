//spiral matrix starting from center

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n, -1));
        int val = 0;

        // Find center
        int x = n / 2;
        int y = n / 2;
        if (n % 2 == 0) {
            x--;
            y--;
        }

        // Directions: right, down, left, up
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        grid[x][y] = val++;
        int steps = 1;

        while (val < n * n) {
            for (int d = 0; d < 4; ++d) {
                for (int s = 0; s < steps; ++s) {
                    x += dir[d].first;
                    y += dir[d].second;
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        grid[x][y] = val++;
                        if (val == n * n) break;
                    }
                }
                if (val == n * n) break;
                if (d == 1 || d == 3) steps++;  // Increase step size after vertical moves
            }
        }

        // Print the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    }
}




#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        
        int cx = (n - 1) / 2, cy = (n - 1) / 2;
        grid[cx][cy] = 0;
        
        int current = 1;
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // Right, Down, Left, Up
        int dir = 0; // Start with right
        int steps = 1;
        int x = cx, y = cy;
        int layer = 1;
        
        while (current < n * n) {
            for (int i = 0; i < 2; ++i) { // Two directions per layer
                for (int j = 0; j < steps; ++j) {
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    grid[x][y] = current++;
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        
        for (auto& row : grid) {
            for (int num : row) {
                cout << num << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
