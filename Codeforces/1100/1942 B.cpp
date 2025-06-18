ps link : https://codeforces.com/problemset/problem/1942/B

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i < n; i++){
	        cin>>a[i];
	    }
	    long long int s = n*1ll*(n-1)/2;
	    int cur = 0;
	    int ans[n];
	    map<int,int> m;
	    for(int i = 0; i < n-1; i++){       // can go till n
	        if(a[i] > 0){               //can be >= 0 as well
	            ans[i] = cur;
	            cur++;
	        } else {
	            ans[i] = cur - a[i];
	            if(ans[i] < 0){
	                ans[i] = cur;
	                cur++;
	            }
	        }
	        m[ans[i]]++;
	        while(m[cur] > 0) cur++;
	        s -= ans[i];
	        cout<<ans[i]<<" ";
	    }
	    cout<<s<<endl;
	}
}
TC - O(N*logN)
SC - O(N)
