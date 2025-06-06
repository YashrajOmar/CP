ps link: https://codeforces.com/problemset/problem/1324/D



#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
 
    sort(c.begin(), c.end());
 
    long long count = 0;  // Use long long to avoid overflow on large n
    for (int i = 0; i < n; i++) {
        // Find smallest index pos > i where c[i] + c[pos] > 0
        int left = i + 1, right = n, pos = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (c[i] + c[mid] > 0) {
                pos = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
 
        
            count += (n - pos);
        
    }
 
    cout << count << "\n";
    return 0;
