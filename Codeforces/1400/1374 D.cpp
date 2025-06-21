ps link: https://codeforces.com/problemset/problem/1374/D



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        map<long long, long long> m;
        long long ans = 0;
        long long z = 0;
        long long v = LLONG_MAX;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            long long rem = a[i] % k;
            m[rem]++;
            if (rem != 0) {
                if (m[rem] > z) {
                    z = m[rem];
                    v = rem;
                } else if (m[rem] == z) {
                    v = min(rem, v);
                }
            }
        }

        if (v != LLONG_MAX)
            ans = z * k - v + 1;

        cout << ans << '\n';
    }
}

TC - O(N⋅logk)
SC - O(N)

  

//MEMORY LIMIT EXCEEDED
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        map<int, int> m;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m[a[i] % k]++;
        }
        int ans = 0;
        int z = 0;
        for(int i = 1; i < k; i++){
            if(m[i] > z){
                z = m[i];
                ans = (m[i])*k - i + 1;
            }
        }
        cout<<ans<<endl;
    }
}
