ps link: https://codeforces.com/problemset/problem/1907/D


#include <bits/stdc++.h>
using namespace std;

bool can(int k, const vector<pair<int, int>>& seg) {
    int l = 0, r = 0;
    for (auto [li, ri] : seg) {
        l = max(li, l - k);
        r = min(ri, r + k);
        if (l > r) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> seg(n);
        for (int i = 0; i < n; ++i) {
            cin >> seg[i].first >> seg[i].second;
        }

        int low = 0, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid, seg)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
