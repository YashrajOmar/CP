ps link: https://codeforces.com/problemset/problem/1545/A


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), even, odd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }

    sort(a.begin(), a.end());
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    bool ok = true;
    int ei = 0, oi = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (a[i] != even[ei++]) {
                ok = false;
                break;
            }
        } else {
            if (a[i] != odd[oi++]) {
                ok = false;
                break;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


Time: O(n log n)

Space: O(n)
