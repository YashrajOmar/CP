ps link : https://codeforces.com/contest/2084/problem/D


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m ,k;
	    cin>>n>>m>>k;
	    int right = n - m*k + 1;
	    int left = 1;
	    while(left <= right){
	        int mid = (left + right)/2;
	        if(n/mid > m){
	            left = mid + 1;
	        } else {
	            right = mid-1;
	        }
	    }
	    //cout<<left<<endl;
	    int z = max(k , left-1);
	    for(int i = 0; i < n; i++){
	        cout<<i%z<<" ";
	    } cout<<endl;
	}
}

TC - O(N)
SC - O(1)
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i) {
			cout << i % (n < (m + 1) * k ? k : n / (m + 1)) << " \n"[i == n - 1];
		}
	}
	return 0;
}
