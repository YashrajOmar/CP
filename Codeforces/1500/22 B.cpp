ps link: https://codeforces.com/problemset/problem/22/B

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> room(n);
    for (int i = 0; i < n; ++i) {
        cin >> room[i];
    }

    int maxPerimeter = 0;

    // Try every possible rectangle
    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c2 = c1; c2 < m; ++c2) {
                    bool valid = true;

                    for (int i = r1; i <= r2 && valid; ++i) {
                        for (int j = c1; j <= c2; ++j) {
                            if (room[i][j] == '1') {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        int height = r2 - r1 + 1;
                        int width = c2 - c1 + 1;
                        int perimeter = 2 * (height + width);
                        maxPerimeter = max(maxPerimeter, perimeter);
                    }
                }
            }
        }
    }

    cout << maxPerimeter << endl;
    return 0;
}

TC - O(n^2 * m^2 * n * m)
SC - O(1)



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> room(n);
    for (int i = 0; i < n; ++i) {
        cin >> room[i];
    }

    // Build 2D prefix sum for number of occupied cells ('1')
    vector<vector<int>> sum(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            sum[i][j] = (room[i][j] == '1' ? 1 : 0)
                      + (i > 0 ? sum[i - 1][j] : 0)
                      + (j > 0 ? sum[i][j - 1] : 0)
                      - (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);

    auto getSum = [&](int r1, int c1, int r2, int c2) {
        int res = sum[r2][c2];
        if (r1 > 0) res -= sum[r1 - 1][c2];
        if (c1 > 0) res -= sum[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) res += sum[r1 - 1][c1 - 1];
        return res;
    };

    int maxPerimeter = 0;

    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c2 = c1; c2 < m; ++c2) {
                    if (getSum(r1, c1, r2, c2) == 0) {
                        int height = r2 - r1 + 1;
                        int width = c2 - c1 + 1;
                        int perimeter = 2 * (height + width);
                        maxPerimeter = max(maxPerimeter, perimeter);
                    }
                }
            }
        }
    }

    cout << maxPerimeter << endl;
    return 0;
}


TC - O(n² * m²)
SC - O(n * m)

  
