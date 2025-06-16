ps link: https://codeforces.com/problemset/problem/1368/B

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
    ll k;
    cin>>k;
    priority_queue<int, vector<int>, greater<int>> pq; ///faster soln
    for(int i = 0; i < 10; i++){
        pq.push(1);
    }
    ll mul = 1;
    while(mul < k){
        int z = pq.top();
        pq.pop();
        mul /= z;
        z++;
        mul *= z;
        pq.push(z);
    }
    string s = "codeforces";
    int i = 0;
    while(!pq.empty()){
        int n = pq.top();
        pq.pop();
        for (int j = 0; j < n; j++) {
            cout << s[i];
        }
        i++;
    }
    cout << endl;
    return 0;
}

TC - O(logK * log10)

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k;
    cin >> k;

    string s = "codeforces";
    vector<int> cnt(10, 1);

    long long prod = 1;

    while (prod < k) {
        for (int i = 0; i < 10; i++) {
            prod /= cnt[i];
            cnt[i]++;
            prod *= cnt[i];
            if (prod >= k) break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}

TC - O(logK)
