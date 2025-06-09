ps link: https://codeforces.com/problemset/problem/1338/A


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int m = INT_MIN;
        int p = INT_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m = max(a[i], m);
            p = max(p, m - a[i]);
        }
        //cout<<m<<" "<<p<<endl;
        int c = 0;
        while(p > 0){
            p = p/2;
            c++;
        }
        cout<<c<<endl;
    }
}

TC - O(1)
SC - O(1)
