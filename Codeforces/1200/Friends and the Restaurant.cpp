#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), diff(n);

        // Read arrays a and b, compute b[i] - a[i]
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            diff[i] = b[i] - a[i];
        }

        // Sort the difference array
        sort(diff.begin(), diff.end());

        int i = 0, j = n - 1;
        int pairs = 0;

        // Use two-pointer technique to find valid pairs
        while (i < j) {
            // If the current smallest + largest diff is non-negative,
            // it's a valid pair (can form a team)
            if (diff[i] + diff[j] >= 0) {
                pairs++;
                i++;
                j--;
            } else {
                // Otherwise, move the left pointer forward
                i++;
            }
        }

        cout << pairs << endl;
    }

    return 0;
}
