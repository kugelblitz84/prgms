#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

int fib(int a,int b,int c,int d,int e){
    int ans = 0;
    if(a + b == c) ans++;
    if(b + c == d) ans++;
    if(c + d == e) ans++;
    return ans;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // a3 = a + b, c - b, 
    cout << max(fib(a, b, a + b, c, d), max(fib(a, b, c - b, c, d), fib(a, b, d - c, c, d))) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}