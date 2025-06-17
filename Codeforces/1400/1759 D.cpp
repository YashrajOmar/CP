ps link: https://codeforces.com/problemset/problem/1759/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int count_factor(ll n, int factor) {
    int count = 0;
    while (n % factor == 0) {
        n /= factor;
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        int cnt2 = count_factor(n, 2);
        int cnt5 = count_factor(n, 5);

        ll mul = 1;
        // Increase power of 5 to match cnt2
        while (cnt2 > cnt5 && mul * 5 <= m) {
            mul *= 5;
            cnt5++;
        }
        // Increase power of 2 to match cnt5
        while (cnt5 > cnt2 && mul * 2 <= m) {
            mul *= 2;
            cnt2++;
        }

        // Now balance further with 10s
        while (mul * 10 <= m) {
            mul *= 10;
        }

        // Maximize by multiplying extra factor
        ll extra = m / mul;
        mul *= extra;

        cout << n * mul << endl;
    }
}


TC - O(t * (log n + log m))
SC - O(1)
