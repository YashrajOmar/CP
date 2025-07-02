https://codeforces.com/problemset/problem/2077/A


for test_case in range(int(input())):
    n = int(input())
    b = sorted([int(_) for _ in input().split()])
    
    a = [0 for _ in range(2*n+1)]
    
    # Implementation note: 0-based index used here
    # assign a[0], a[2], ... large numbers
    for i in range(0, n+1):
        a[2*i] = b[n+i-1]
        
    # assign a[1], a[3], .. small numbers
    for i in range(0, n-1):
        a[2*i+1] = b[i]
        
    
    a[2*n-1] = sum(b[n-1:]) - sum(b[:n-1])
    print(*a)
    
# model solution
TC - O(n * logn)
SC - O(N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        set<int> unique_elements;

        // Read 2n elements and insert into set for uniqueness check
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            unique_elements.insert(a[i]);
        }

        // Sort in descending order
        sort(a.begin(), a.end(), greater<int>());

        // Compute alternating sum
        int sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            sum += (i % 2 == 0) ? a[i] : -a[i];
        }

        cout << sum << endl;

        // Check if sum is not present in the array and is positive
        if (sum > 0 && unique_elements.find(sum) == unique_elements.end()) {
            // Print sum and the array as is
            cout << sum << " ";
            for (int val : a) {
                cout << val << " ";
            }
            cout << endl;
        } else {
            // Adjust the first element to match sum requirement
            int adjusted_first = a[0];
            int x = adjusted_first - (sum - adjusted_first); // x = 2*adjusted_first - sum

            cout << adjusted_first << " " << x << " ";
            for (int i = 1; i < 2 * n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
