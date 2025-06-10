ps link: https://codeforces.com/problemset/problem/1551/C

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        vector<vector<int>> m(n, vector<int>(5, 0));
 
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            for(char ch : v[i]) {
                m[i][ch - 'a']++;
            }
        }
 
        int ans = 0;
 
        // Try making each character from 'a' to 'e' dominant
        for(int ch = 0; ch < 5; ch++) {
            vector<int> diffs;
            for(int i = 0; i < n; i++) {
                int total = v[i].size();
                int dominant = m[i][ch];
                // Score = how favorable this string is to making ch dominant
                diffs.push_back(2 * dominant - total);
            }
 
            // Greedy: sort and pick maximum positive cumulative sum
            sort(diffs.rbegin(), diffs.rend());
            int sum = 0, count = 0;
            for(int d : diffs) {
                if(sum + d > 0) {
                    sum += d;
                    count++;
                } else break;
            }
            ans = max(ans, count);
        }
 
        cout << ans << endl;
    }
    return 0;
}

O(N*logN)
