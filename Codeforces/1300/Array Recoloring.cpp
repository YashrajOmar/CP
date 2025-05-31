ps link: https://codeforces.com/problemset/problem/2075/B


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long m = 0;
        if (k == 1) {
            m = max(a[n - 1] + a[0], m);
            for (int i = 1; i < n - 1; i++) {
                m = max({m, a[i] + a[0], a[i] + a[n - 1]});
            }
            cout << m << endl;
        } else {
            sort(a.begin(), a.end(), greater<long long>());
            int count = min(k + 1, n); // Ensure we don't access out-of-bounds
            for (int i = 0; i < count; i++) {
                m += a[i];
            }
            cout << m << endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        long long int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        long long m = 0;
        if(k == 1){
            m = max(m, a[n-1] + a[0]);
            for(int i = 1; i < n-1; i++){
                m = max(a[i] + a[0], m);
                m = max(a[i] + a[n-1], m);
            }
            cout<<m<<endl;
        } else {
            sort(a, a+n);
            int i = n-1;
            while(k >= 0){
                m += a[i];
                i--;
                k--;
            }
            cout<<m<<endl;
        }
    }
}


Overall Time Complexity = O(T × (n log n)) in worst case
Overall Space Complexity = O(n)
