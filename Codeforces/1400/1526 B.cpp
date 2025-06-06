ps link: https://codeforces.com/problemset/problem/1526/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;  // FIXED: Read the value of n
        bool found = false;

        for (int i = 0; i <= n / 11; i++) {
            int x = 11 * i;
            if ((n - x) % 111 == 0) {
                found = true;
                break; // No need to continue once found
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;
 
        for (int b = 0; b <= 10; b++) {
            if (n >= 111 * b && (n - 111 * b) % 11 == 0) {
                found = true;
                break;
            }
        }
 
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}
