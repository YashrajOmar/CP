ps link : https://codeforces.com/problemset/problem/2/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> rounds(n);
    map<string, int> finalScore;

    // First pass: input + compute final scores
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        rounds[i] = {name, score};
        finalScore[name] += score;
    }

    // Find max score and players who achieved it
    int maxScore = INT_MIN;
    for (auto &[name, score] : finalScore) {
        maxScore = max(maxScore, score);
    }

    // Count how many players achieved maxScore
    int maxCount = 0;
    for (auto &[name, score] : finalScore) {
        if (score == maxScore) maxCount++;
    }

    if (maxCount == 1) {
        // Unique winner, print directly
        for (auto &[name, score] : finalScore) {
            if (score == maxScore) {
                cout << name << endl;
                break;
            }
        }
    } else {
        // Multiple players tied → track who reached maxScore first
        map<string, int> runningScore;
        for (auto &[name, score] : rounds) {
            runningScore[name] += score;
            if (finalScore[name] == maxScore && runningScore[name] >= maxScore) {
                cout << name << endl;
                break;
            }
        }
    }

    return 0;
}


TC - O(N)
SC - O(N)
