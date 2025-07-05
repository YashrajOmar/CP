ps link: https://codeforces.com/problemset/problem/1714/D

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end, index;
};

int main() {
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];

        vector<Interval> intervals;
        int len = t.size();

        // Step 1: Find all valid intervals
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < n; ++j) {
                int l = s[j].size();
                if (i + l <= len && t.substr(i, l) == s[j]) {
                    intervals.push_back({i, i + l - 1, j + 1}); // 1-based index
                }
            }
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start || (a.start == b.start && a.end > b.end);
        });

        vector<pair<int, int>> result;
        int cur = 0;
        bool possible = true;

        while (cur < len) {
            int best_end = -1;
            Interval best_interval = {-1, -1, -1};

            for (const auto& inter : intervals) {
                if (inter.start > cur) break;
                if (inter.start <= cur && inter.end >= best_end) {
                    best_end = inter.end;
                    best_interval = inter;
                }
            }

            if (best_end == -1 || best_end < cur) {
                possible = false;
                break;
            }

            result.push_back({best_interval.index, best_interval.start + 1}); // 1-based position
            cur = best_end + 1;
        }

        if (!possible) {
            cout << -1 << "\n";
        } else {
            cout << result.size() << "\n";
            for (auto& p : result) {
                cout << p.first << " " << p.second << "\n";
            }
        }
    }

    return 0;
}


TC - O(len × n × 10)
SC - O(N*10)
