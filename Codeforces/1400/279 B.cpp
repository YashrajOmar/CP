ps link: https://codeforces.com/problemset/problem/279/B


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n, t;
    cin>>n>>t;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    //sort(a, a+n);
    int m = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    while(i < n){
        if(sum <= t){
            sum += a[i];
            i++;
        } else {
            m = max(m, i - j - 1);
            sum -= a[j];
            j++;
        }
    }
    if(sum <= t) m = max(m, i - j);
    else m = max(m, i - j - 1);
    cout<<m<<endl;
}

TC - O(N)
SC - O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    
    int max_books = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] > t) continue;
        long long target = prefix[i - 1] + t;
        auto it = upper_bound(prefix.begin() + i, prefix.end(), target);
        int j = (it - prefix.begin()) - 1;
        max_books = max(max_books, j - (i - 1));
    }
    
    cout << max_books << endl;
    return 0;
}
TC - O(N)
SC - O(N)

