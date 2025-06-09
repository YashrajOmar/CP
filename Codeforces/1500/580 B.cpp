ps link: https://codeforces.com/problemset/problem/580/B

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;


int main() {
	// your code goes here
    int n, d;
    cin>>n>>d;
    vector<pair<int,int> > v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end());
    long long m = 0;
    int j = 0;
    long long s = 0;
    for(int i = 0; i < n; i++){
        while(v[i].f - v[j].f >= d){
            s -= v[j].s;
            j++;
        }
        s += v[i].s;
        m = max(s, m);
        //cout<<m<<endl;
    }
    cout<<m<<endl;
}


TC - O(N*logN)
SC - O(1)
