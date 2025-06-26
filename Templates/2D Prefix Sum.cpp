#include <vector>
using namespace std;

// Build 2D prefix sum from a 2D grid (any numeric type)
vector<vector<int>> build2DPrefixSum(const vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prefix[i][j] = grid[i][j]
                         + (i > 0 ? prefix[i - 1][j] : 0)
                         + (j > 0 ? prefix[i][j - 1] : 0)
                         - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
        }
    }

    return prefix;
}

TC - O(N * M)
SC - O(N * M)

// Query sum of subrectangle [(r1,c1), (r2,c2)] in O(1)
int query2DPrefixSum(const vector<vector<int>>& prefix, int r1, int c1, int r2, int c2) {
    int total = prefix[r2][c2];
    if (r1 > 0) total -= prefix[r1 - 1][c2];
    if (c1 > 0) total -= prefix[r2][c1 - 1];
    if (r1 > 0 && c1 > 0) total += prefix[r1 - 1][c1 - 1];
    return total;
}

TC - O(1)

