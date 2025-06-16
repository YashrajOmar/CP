ps link: https://codeforces.com/problemset/problem/1399/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> o;
        vector<int> z;
        vector<int> a(n);
        int x = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(z.empty()){
                    o.push_back(x+1);
                    a[i] = x+1;
                    x++;
                } else {
                    o.push_back(z.back());
                    z.pop_back();
                    a[i] = o.back();
                }
            } else {
                if(o.empty()){
                    z.push_back(x+1);
                    a[i] = x+1;
                    x++;
                } else {
                    z.push_back(o.back());
                    o.pop_back();
                    a[i] = z.back();
                }
            }
        }
        cout << x << endl;  // ✅ total subsequences used//  cout<<(o.size() + z.size())<<endl;
        for(auto it: a){
            cout << it << " ";
        } cout << endl;
    }
}

TC - O(N)
SC - O(N)
