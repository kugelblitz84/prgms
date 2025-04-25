#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int32_t n , m;
    cin >> n >> m;
    int32_t k = 31 - __builtin_clz(n ^ m);
    int a = n | (1 << k) - 1, b = a + 1, c = (a == n ? m : n);
    cout << a << ' ' << b << ' ' << c << '\n';
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