ps link: https://codeforces.com/problemset/problem/1985/F

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool s(ll sum, ll x, vector<ll> &a, vector<ll> &c, ll n, ll h){
    for(int i = 0; i < n; i++){
        sum += (x / c[i])*a[i];
        if(sum >= h) return true;
    }
    return sum >= h;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        ll h, n;
        cin>>h>>n;
        vector<ll> a(n), c(n);
        ll sum = 0;
        for(int i =0; i < n; i++){
            cin>>a[i];
            sum += a[i];
        } 
        for(int i =0; i < n; i++){
            cin>>c[i];
            
        } 
        ll m = 0;
        for(int i =0; i < n; i++){
            m = max(m, (h / a[i] + 1)*c[i]);
        } 
        ll left = 1;
        ll right = m;
        while(left <= right){
            ll mid = left + (right - left)/2;
            if(s( sum, mid - 1, a, c, n, h)){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout<<left<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int h, n; cin >> h >> n;
		vector<int> a(n), c(n);
		for(int& i: a) cin >> i;
		for(int& i: c) cin >> i;
		set<pair<long long, int>> S;
		for(int i = 0; i < n; i++){
			S.insert({1, i});
		}
		long long last_turn = 1;
		while(h > 0){
			auto [turn, i] = *S.begin();
			S.erase(S.begin());
			last_turn = turn;
			h -= a[i];
			S.insert({turn + c[i], i});
		}
		cout << last_turn << "\n";
	}
}


TC - O(N*logN)
