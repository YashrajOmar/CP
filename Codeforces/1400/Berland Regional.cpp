ps link: https://codeforces.com/problemset/problem/1519/C


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> u(n), s(n);

        for (int i = 0; i < n; i++) cin >> u[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        map<int, vector<int>> team_skills;

        for (int i = 0; i < n; i++) {
            team_skills[u[i]].push_back(s[i]);
        }

        vector<long long> ans(n + 1, 0); // 1-based index

        for (auto &[team, skills] : team_skills) {
            sort(skills.rbegin(), skills.rend()); // sort in descending
            int sz = skills.size();
            vector<long long> prefix(sz + 1, 0);

            for (int i = 0; i < sz; i++) {
                prefix[i + 1] = prefix[i] + skills[i];
            }

            // For every possible team size k from 1 to sz
            for (int k = 1; k <= sz; k++) {
                int complete_teams = sz / k;
                ans[k] += prefix[complete_teams * k];
            }
        }

        for (int k = 1; k <= n; k++) {
            cout << ans[k] << " ";
        }
        cout << "\n";
    }
}

TC - O(T*NlogN)
SC - O(N)
