ps link: https://codeforces.com/contest/489/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || s > 9 * m) {
        cout << "-1 -1" << endl;
    } else {
        // Construct largest number
        string largest = "";
        int sum = s;
        for (int i = 0; i < m; i++) {
            int digit = min(9, sum);
            largest += (digit + '0');
            sum -= digit;
        }

        // Construct smallest number by reversing and adjusting for leading zero
        string smallest = largest;
        reverse(smallest.begin(), smallest.end());

        if (smallest[0] == '0') {
            for (int i = 1; i < m; i++) {
                if (smallest[i] != '0') {
                    smallest[i]--;
                    smallest[0] = '1';
                    break;
                }
            }
        }

        cout << smallest << " " << largest << endl;
    }
}

