

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'

// Fenwick Tree / Binary Indexed Tree
struct FenwickTree {
    vector<ll> bit;
    int n;

    FenwickTree(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, ll val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll prefix_sum(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    ll range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

int main() {
    fastio;

    int n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1);
    FenwickTree ft(n);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        ft.add(i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            ll delta = u - arr[k];
            arr[k] = u;
            ft.add(k, delta);
        } else {
            int a, b;
            cin >> a >> b;
            cout << ft.range_sum(a, b) << endl;
        }
    }

    return 0;
}
