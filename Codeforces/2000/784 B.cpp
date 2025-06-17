ps link: https://codeforces.com/problemset/problem/784/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Map of hex digits to the number of holes
    map<char, int> holes = {
        {'0', 1}, {'4', 1}, {'6', 1}, {'8', 2}, {'9', 1},
        {'A', 1}, {'B', 2}, {'D', 1}
    };

    stringstream ss;
    ss << hex << uppercase << n;
    string z = ss.str();  // Hex representation

    cout << z << endl;

    int sum = 0;
    for (char c : z) {
        sum += holes[c];  // Adds 0 if c is not in the map
    }

    cout << sum << endl;
}


Total Time Complexity: O(logn)
​Space Complexity: O(logn)
​

