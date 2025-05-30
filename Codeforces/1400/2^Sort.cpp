#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int streak = 1, ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < 2 * a[i + 1]) {
                ++streak;
            } else {
                if (streak > k) ans += (streak - k);
                streak = 1;
            }
        }
        if (streak > k) ans += (streak - k);  // last streak
        cout << ans << '\n';
    }
}



#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector < long long int > a(n), mods;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mods.push_back(a[i] % 10);
        }

        int len = 1;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < 2 * a[i + 1]) {
                len++;
            } else {
                ans += max(0, len - k);
                len = 1;
            }
        }
        ans += max(0, len - k);
        cout << ans << endl;
    }
}
