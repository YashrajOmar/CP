ps link: https://codeforces.com/problemset/problem/1999/F



#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 200005;
const ll mod = 1e9 + 7;

ll fact[MAX], invfact[MAX];

ll power(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = fact[i - 1] * i % mod;
        invfact[i] = power(fact[i], mod - 2);
    }
}

ll comb(ll n, ll r){
    if(r > n || r < 0) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x == 0) cnt0++;
            else cnt1++;
        }

        int minOnes = max((k + 1) / 2, k - cnt0);
        int maxOnes = min(k, cnt1);

        if(minOnes > maxOnes){
            cout << 0 << '\n';
            continue;
        }

        ll ans = 0;
        for(int i = minOnes; i <= maxOnes; i++){
            ll ways = comb(cnt1, i) * comb(cnt0, k - i) % mod;
            ans = (ans + ways) % mod;
        }

        cout << ans << '\n';
    }
}


 Time Complexity : O(max N + K)
 Space Complexity : O(max N)
