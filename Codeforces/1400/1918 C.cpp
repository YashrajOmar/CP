ps link: https://codeforces.com/problemset/problem/1918/C

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        ll a, b, r;
        cin >> a >> b >> r;
        ll x = 0;
        if (a > b) {
            ll temp = a;
            a = b;
            b = temp;
        }
        bool found = false;

        for (int i = 60; i >= 0; i--) {
            int y = (a >> i) & 1;
            int z = (b >> i) & 1;

            if (z != y && z == 1) {
                if (!found) {
                    found = true;
                } else {
                    if ((x ^ (1ll << i)) <= r) {
                        x ^= (1ll << i);
                        a ^= (1ll << i);
                        b ^= (1ll << i);
                    }

                }
            }
        }

        cout << b - a << endl;
        //cout<<x<<endl;
    }
}

TC - O(60)
SC - O(1)
