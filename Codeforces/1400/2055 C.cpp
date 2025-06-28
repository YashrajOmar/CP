ps link: https://codeforces.com/problemset/problem/2055/C


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        int p = s.size();
        int k = 0;
        vector<vector<ll>> a(n, vector<ll> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>a[i][j];
            }
        }
        int i = 0;
        int j = 0;
        while(k < p){
            ll x = 0;
            if(s[k] == 'D'){
                for(int q = 0; q < m; q++){
                    x += a[i][q];
                }
                a[i][j] = -x;
                i++;
            } else {
                for(int q = 0; q < n; q++){
                    x += a[q][j];
                }
                a[i][j] = -x;
                j++;
            }
            k++;
        }
        ll x = 0;
        for(int q = 0; q < m; q++){
            x += a[i][q];
        }
        a[i][j] = -x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               cout<<a[i][j]<<" ";
            }cout<<endl;
        }
    }
}
TC - O(N*M)
SC - O(N*M)
