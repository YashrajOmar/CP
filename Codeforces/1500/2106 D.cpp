ps link: https://codeforces.com/problemset/problem/2106/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T>
void printVector(const vector<T>& v, const string& name = "") {
    if (!name.empty()) cout << name << ": ";
    for (const auto& elem : v)
        cout << elem << " ";
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<int> prefix(m + 1, 0);
    int ptrA = 0, ptrB = 0;
    while (ptrA < n && ptrB < m) {
        if (a[ptrA] >= b[ptrB]) {
            prefix[ptrB + 1] = ptrA + 1;
            ptrB++;
        }
        ptrA++;
    }
    if (ptrB == m) {
        cout << 0 << endl;
        return;
    }
    for (int i = ptrB + 1; i <= m; i++) prefix[i] = n + 1;

    vector<int> suffix(m + 2, n + 1);
    ptrA = n - 1, ptrB = m - 1;
    while (ptrA >= 0 && ptrB >= 0) {
        if (a[ptrA] >= b[ptrB]) {
            suffix[ptrB + 1] = ptrA + 1;
            ptrB--;
        }
        ptrA--;
    }
    for (int i = ptrB + 1; i >= 0; i--) suffix[i] = 0;

    // Debug prints after both prefix and suffix are calculated:
    printVector(a, "a");
    printVector(b, "b");
    printVector(prefix, "prefix");
    printVector(suffix, "suffix");

    int ans = INT_MAX;
    for (int j = 1; j <= m; j++) {
        if (prefix[j - 1] < suffix[j + 1]) {
            ans = min(ans, b[j - 1]);
        }
    }

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
