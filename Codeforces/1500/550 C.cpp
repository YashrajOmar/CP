ps link: https://codeforces.com/problemset/problem/550/C


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();

    // All numbers divisible by 8 up to 999 (3 digits max)
    for (int i = 0; i < 1000; i += 8) {
        string num = to_string(i);
        int p = 0; // pointer in num

        // Try to find all characters of num in s in order
        for (int j = 0; j < len; j++) {
            if (s[j] == num[p]) {
                p++;
                if (p == num.length()) break;
            }
        }

        if (p == num.length()) {
            cout << "YES\n" << num << endl;
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

Time Complexity: O(n)
space : O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Check for single-digit 0 or 8
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' || s[i] == '8') {
            cout << "YES\n" << s[i] << endl;
            return 0;
        }
    }

    // Check for two-digit numbers
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        for (int j = i + 1; j < n; ++j) {
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if (num % 8 == 0) {
                cout << "YES\n" << s[i] << s[j] << endl;
                return 0;
            }
        }
    }

    // Check for three-digit numbers
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (num % 8 == 0) {
                    cout << "YES\n" << s[i] << s[j] << s[k] << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
Time Complexity: O(N^3)
