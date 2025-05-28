#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& v : a) cin >> v;

        map<int, int> prime_count;

        for (int x : a) {
            for (int i = 2; i * i <= x; ++i) {
                while (x % i == 0) {
                    prime_count[i]++;
                    x /= i;
                }
            }
            if (x > 1) prime_count[x]++;
        }

        bool possible = true;
        for (auto& [prime, count] : prime_count) {
            if (count % n != 0) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << '\n';
    }

    return 0;
}
