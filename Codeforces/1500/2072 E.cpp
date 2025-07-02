https://codeforces.com/problemset/problem/2072/E

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        if (k == 0){
            cout<<0<<endl;
        continue; // No output if k == 0
}
        vector<pair<int, int>> points;
        int y = 0;
        int x = 0;
        while (k > 0 && points.size() < 500) {
            int m = 1;
            // Find largest m such that m*(m-1)/2 ≤ k and total points ≤ 500
            while ((m - 1) * m / 2 <= k && points.size() + m <= 500) {
                m++;
            }
            m--;

            for (int i = 0; i < m; ++i) {
                points.emplace_back(x+i, y);
            }

            k -= m * (m - 1) / 2;
           // cout<<m<<endl;
            y += 1;
            x += m;
        }

        cout << points.size() << "\n";
        for (auto &[x, y] : points) {
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}

TC - O(T * (√k + n)) ≈ O(T * 500)
SC - O(n) = O(500) = O(1)
