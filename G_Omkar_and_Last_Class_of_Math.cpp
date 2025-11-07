#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = n - 1;
    pair<int, int> res = {1, n - 1};
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int x = n / i;
            int y = n - x;
            if(max(x, y) < ans){
                ans = max(x, y);
                res = {min(x, y), max(x, y)};
            }
        }
        
    }

    cout << res.first << ' ' << res.second << '\n';
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