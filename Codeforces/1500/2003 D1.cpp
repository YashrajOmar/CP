ps link: https://codeforces.com/problemset/problem/2003/D1


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int max_mex = 0;  // This will store the maximum "modified MEX" value across all sequences

        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;

            map<int, int> freq;  // Count frequency of integers in this sequence
            while (l--) {
                int v;
                cin >> v;
                freq[v]++;
            }

            // Step 1: Find the smallest non-negative integer not present — the MEX
            int mex1 = 0;
            while (freq[mex1]) mex1++;

            // Step 2: Continue to find the next smallest integer not present
            int mex2 = mex1 + 1;
            while (freq[mex2]) mex2++;

            // The modified MEX value is the second missing integer
            max_mex = max(max_mex, mex2);
        }

        ll ans = 0;
        if (m > max_mex) {
            // If m is greater than max_mex
            // Use arithmetic formula for sum of first m natural numbers
            ans = 1LL * max_mex * max_mex - 1LL * max_mex * (max_mex - 1) / 2 + 1LL * m * (m + 1) / 2;
        } else {
            // If m <= max_mex
            ans = 1LL * (m + 1) * max_mex;
        }

        cout << ans << endl;
    }

    return 0;
}

Time Complexity: O(t * n * k log k)   //k = average length of each sequence (assume max element is bounded by k)
 Space Complexity: O(k)
