#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Count of valid pairs
        long long count = 0;

        // Map to store the frequency of required matching remainders
        map<pair<long long, long long>, long long> remainderMap;

        for (long long i = 0; i < n; i++) {
            long long modX = a[i] % x;
            long long modY = a[i] % y;

            // Check how many previous elements satisfy the condition
            count += remainderMap[{modX, modY}];

            // Insert the required value for future matching
            long long requiredModX = (x - modX + x) % x;  // handles mod safely
            remainderMap[{requiredModX, modY}]++;
        }

        cout << count << endl;
    }

    return 0;
}
