ps link: https://codeforces.com/problemset/problem/2111/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a, a + m);
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 0) {
                for (int j = 0; j < 3; j++) {
                    cout << a[i/2] << " " << a[m - 1 - i/2] << " ";
                }
                cout << endl;
            }
            else {
                for (int j = 0; j < 3; j++) {
                    cout << a[m - 1 - (i-1)/2] << " " << a[(i-1)/2] << " ";
                }
                cout << endl;
            }
        }
    }
}

TC - O(M*logM + N)
SC - O(1)


