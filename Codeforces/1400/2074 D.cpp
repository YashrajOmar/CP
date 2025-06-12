ps link:  https://codeforces.com/problemset/problem/2074/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), r(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> r[i];
        
        int max_r = *max_element(r.begin(), r.end());
        vector<vector<pair<int, int>>> intervals(max_r + 1);
        
        for (int i = 0; i < n; ++i) {
            int xi = x[i], ri = r[i];
            for (int y = 0; y <= ri; ++y) {
                long long val = (long long)ri * ri - (long long)y * y;
                int s = sqrt(val);
                int a = xi - s, b = xi + s;
                intervals[y].emplace_back(a, b);
            }
        }
        
        long long total = 0;
        for (int y = 0; y <= max_r; ++y) {
            auto& iv = intervals[y];
            if (iv.empty()) continue;
            
            sort(iv.begin(), iv.end());
            vector<pair<int, int>> merged;
            for (auto [a, b] : iv) {
                if (merged.empty() || a > merged.back().second + 1)
                    merged.emplace_back(a, b);
                else
                    merged.back().second = max(merged.back().second, b);
            }
            
            long long sum = 0;
            for (auto [a, b] : merged)
                sum += b - a + 1;
            
            total += (y == 0) ? sum : 2 * sum;
        }
        cout << total << '\n';
    }
    return 0;
}


TC - O(N*logN)
SC - O(N)


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> center(n), radius(n);
        for (int i = 0; i < n; i++) cin >> center[i];
        for (int i = 0; i < n; i++) cin >> radius[i];

        // Map to store max height (2a + 1) for each x-position
        map<ll, ll> maxYCount;

        // Custom integer sqrt function to avoid floating point inaccuracies
        auto isqrt = [](ll x) {
            ll val = sqrtl(x) + 5;
            while (val * val > x) val--;
            return val;
        };

        for (int i = 0; i < n; i++) {
            ll x_center = center[i];
            ll r = radius[i];
            // Sweep over all x-values covered by the circle
            for (ll x = x_center - r; x <= x_center + r; x++) {
                ll dx = x - x_center;
                ll y_square = r * r - dx * dx;
                if (y_square < 0) continue;
                ll y_max = isqrt(y_square);
                maxYCount[x] = max(maxYCount[x], 2 * y_max + 1);
            }
        }

        // Sum the total number of integer points across all x-values
        ll totalPoints = 0;
        for (auto &[x, count] : maxYCount) {
            totalPoints += count;
        }

        cout << totalPoints << '\n';
    }

    return 0;
}
