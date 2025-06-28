ps link: https://codeforces.com/problemset/problem/1857/C


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int m=n*(n-1)/2,b[m];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(b,b+m);
        for(int i=0;i<m;i+=--n)cout<<b[i]<<' ';
        cout<<"1000000000\n";
    }
}

TC - O(n^2*logn)
SC - O(n^2)
