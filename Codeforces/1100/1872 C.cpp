ps link: https://codeforces.com/problemset/problem/1872/C


#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int pre[N];

// ✅ Valid: this is inside a function
void precompute() {
    for (int i = 2; i*i < N; i++) {
        if (pre[i] == 0) {
            for (int j = i*i; j < N; j += i) {
                if (pre[j] == 0)
                    pre[j] = i;
            }
        }
    }
}

int main() {
	// your code goes here
	precompute();
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        if((r % 2 == 0 && r/2 != 1)  ){
            cout<<r/2<<" "<<r/2<<endl;
        } else if (r > l && r/2 != 1) {
            cout<<r/2<<" "<<r/2<<endl;
        }
        else if(l == r && pre[r] != 0){
            cout<<pre[r]<<" "<<r-pre[r]<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}

TC - O(1e7)
SC - O(1e7)
