ps link: https://codeforces.com/problemset/problem/276/C


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> v(n+1, 0);
    while(q--){
        int x, y;
        cin>>x>>y;
        v[x-1]++;
        v[y]--;
    }
    for(int i = 0; i < n; i++){
        v[i+1] += v[i];
    }
    // for(auto it: v){
    //     cout<<it<<" ";
    // } cout<<endl;
    sort(v.rbegin(), v.rend());
    sort(a, a+n);
    reverse(a, a+n);
    long long s = 0;
    for(int i = 0; i < n; i++){
        s += (long long)a[i]*v[i];
    }
    cout<<s<<endl;
}
TC - O(N* logN)
SC - O(1)
