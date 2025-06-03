ps link: https://codeforces.com/problemset/problem/1520/E



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;

        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (x[i] == '*') a.push_back(i);
        }

        int m = a.size();
        if (m == 0) {
            cout << 0 << endl;
            continue;
        }

        int cen = a[m / 2]; // median position
        long long s = 0;

        // align positions to consecutive slots starting from cen - m/2
        for (int i = 0; i < m; i++) {
            s += abs(a[i] - (cen - m / 2 + i));
        }

        cout << s << endl;
    }
    return 0;
}


TC- O(N)

#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        vector < int > a;
        for (int i = 0; i < n; i++) {
            if (x[i] == '*') a.push_back(i + 1);
        }
        int m = a.size();
        int cen;
        if (m == 0) cout << 0 << endl;
        else {
            // if (m % 2 == 0) {
            //     cen = (a[m / 2] + a[m / 2 + 1]) / 2;
            // } else {
            //     cen = a[m / 2];
            // }
            cen = a[m / 2];
            int left = m / 2 - 1;
            int temp = cen;
            long long int s = 0;
            while (left >= 0) {
                temp--;
                s += abs(temp - a[left--]);
            }
            int right = m / 2 + 1;
            temp = cen;
            while (right < m) {

                temp++;
                s += abs(a[right++] - temp);
            }
            cout << s << endl;
        }
    }
}
