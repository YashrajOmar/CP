ps link: https://codeforces.com/contest/1648/problem/A


#include <bits/stdc++.h>
using namespace std;

long long computeDistance(vector<int> &v) {
    sort(v.begin(), v.end());
    long long total = 0, prefixSum = 0;
    for (int i = 0; i < v.size(); i++) {
        total += 1LL * v[i] * i - prefixSum;
        prefixSum += v[i];
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> mp;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mp[a[i][j]].emplace_back(i, j);
        }

    long long s = 0;
    for (auto &[val, positions] : mp) {
        vector<int> rows, cols;
        for (auto &[x, y] : positions) {
            rows.push_back(x);
            cols.push_back(y);
        }
        s += computeDistance(rows);
        s += computeDistance(cols);
    }

    cout << s << endl;
    return 0;
}


TC -  O(K log K).
