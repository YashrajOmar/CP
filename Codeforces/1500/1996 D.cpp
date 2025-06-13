ps link: https://codeforces.com/problemset/problem/1996/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll s = 0;
        for(ll a = 1; a <= min(n,x); a++){
            for(ll b = 1;  a * b <= n and a + b <= x; b++){
                if(n >= a * b){
                    ll c_max = (n - a * b) / (a + b);
                    c_max = min(c_max, x - a - b);
                    if(c_max >= 1)
                        s += c_max;
                }
            }
        }
        cout << s << endl;
    }
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll ans = 0;
        for(ll a = 1; a <= x - 2; a++) {
            ll b_max = min(n / a, x - a - 1);
            for(ll b = 1; b <= b_max; b++) {
                ll c_max = min((n - a * b) / (a + b), x - a - b);
                if (c_max >= 1) 
                    ans += c_max;
            }
        }
        cout << ans << endl;
    }
}
