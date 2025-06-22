ps link: https://codeforces.com/problemset/problem/2117/E


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        unordered_map<int, pair<int, int>> m;
        for (int i = n - 1; i >= 0; i--) {
            if (m.find(a[i]) != m.end()) {
                if (m[a[i]].second == 1) {
                    cout << i + 1 << endl;
                    goto case_done;
                } else {
                    if (m[a[i]].first - i != 1) {
                        cout << i + 1 << endl;
                        goto case_done;
                    }
                }
            } else {
                m[a[i]] = {i, 1};
            }

            if (m.find(b[i]) != m.end()) {
                if (m[b[i]].second == 2) {
                    cout << i + 1 << endl;
                    goto case_done;
                } else {
                    if (m[b[i]].first - i != 1) {
                        cout << i + 1 << endl;
                        goto case_done;
                    }
                }
            } else {
                m[b[i]] = {i, 2};
            }
        }
        cout<<0<<endl;
        case_done:;
    }
}



#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    unordered_map<int, pair<int, int>> m;
    for(int i = n-1; i >= 0; i--){
        if(m.find(a[i]) != m.end()){
            if(m[a[i]].second == 1){
                cout << i+1 << endl;
                return;
            } else {
                if(m[a[i]].first - i != 1){
                    cout << i+1 << endl;
                    return;
                }
            }
        } else {
            m[a[i]] = {i, 1};
        }

        if(m.find(b[i]) != m.end()){
            if(m[b[i]].second == 2){
                cout << i+1 << endl;
                return;
            } else {
                if(m[b[i]].first - i != 1){
                    cout << i+1 << endl;
                    return;
                }
            }
        } else {
            m[b[i]] = {i, 2};
        }
    }
    cout<<0<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve(); // handles one test case and returns early if needed
    }
}


TC - O(N*logN)
SC - O(N)
