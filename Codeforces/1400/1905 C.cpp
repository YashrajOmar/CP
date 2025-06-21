
ps link: https://codeforces.com/problemset/problem/1905/C


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        char k = 'a';
        vector<pair<char, int>> c;
        string x = s;
        sort(x.begin(), x.end());
        if(s == x){
            cout<<0<<endl;
            continue;
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i] >= k){
                k = s[i];
                c.push_back({s[i], i});
            }
        }
        int l = c.size();
        int z = l-1;
        int ans = 0;
        while(z > 0 && c[z].first == c[z-1].first){
            z--;
            
        }
       
        vector<char> p(s.begin(), s.end());
        vector<char> q(s.begin(), s.end());
        sort(q.begin(), q.end());
        for(int i = 0; i < l/2; i++){
            swap(p[c[i].second], p[c[l-1-i].second]);
        }
        if(p == q){
            cout<<z<<endl;
        } else {
            cout<<-1<<endl;
        }
        // for(auto it: p){
        //     cout<<it<<" ";
        // } cout<<endl;
    }
}

TC - O(N*logN)
SC - O(N)
