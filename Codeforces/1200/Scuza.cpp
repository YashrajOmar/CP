#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n), k(q);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> k[i];
        }

        vector<long long> prem(n), ps(n);
        prem[0] = ps[0] = a[0];
        for (int i = 1; i < n; i++) {
            prem[i] = max(a[i], prem[i - 1]);
            ps[i] = ps[i - 1] + a[i];
        }

        vector<long long> ans(q);
        for (int i = 0; i < q; i++) {
            auto z_ptr = upper_bound(prem.begin(), prem.end(), k[i]);
            int z = z_ptr - prem.begin();  // Index from iterator
            if (z == 0)
                ans[i] = 0;
            else
                ans[i] = ps[z - 1];
        }

        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
