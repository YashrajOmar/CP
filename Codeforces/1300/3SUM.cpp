#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), mods;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mods.push_back(a[i] % 10);
        }

        // Keep only up to 3 of each digit (to ensure max combinations)
        map<int, int> count;
        vector<int> trimmed;
        for (int d : mods) {
            if (count[d] < 3) {
                trimmed.push_back(d);
                count[d]++;
            }
        }

        bool found = false;
        int sz = trimmed.size();
        // Check all combinations of i, j, k (distinct indices)
        for (int i = 0; i < sz && !found; ++i) {
            for (int j = i + 1; j < sz && !found; ++j) {
                for (int k = j + 1; k < sz && !found; ++k) {
                    if ((trimmed[i] + trimmed[j] + trimmed[k]) % 10 == 3) {
                        found = true;
                    }
                }
            }
        }

        cout << (found ? "YES" : "NO") << '\n';
    }
}








python:
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    freq = [0] * 10
    for num in a:
        last_digit = num % 10
        freq[last_digit] += 1
    found = False
    for i in range(10):
        for j in range(10):
            for k in range(10):
                if (i + j + k) % 10 != 3:
                    continue
                required = [0] * 10
                required[i] += 1
                required[j] += 1
                required[k] += 1
                valid = True
                for d in range(10):
                    if required[d] > freq[d]:
                        valid = False
                        break
                if valid:
                    found = True
                    break
            if found:
                break
        if found:
            break
    print("YES" if found else "NO")
