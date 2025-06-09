ps link : https://codeforces.com/problemset/problem/1542/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        bool ok = false;
        
        if (a == 1) {
            // You can only add b repeatedly
            ok = ((n - 1) % b == 0);
        } else {
            long long x = 1;
            while (x <= n) {
                if ((n - x) % b == 0) {
                    ok = true;
                    break;
                }
                x *= a;
            }
        }
        
        cout << (ok ? "Yes" : "No") << endl;
    }
}

TC - O(log N)
SC - O(1)
