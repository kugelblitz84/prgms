#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  l = abs(l);
  int x = 0,y = 0;
  x = min(m, l);
  m -= min(m, l);
  y = min(m, r);
  cout << -x << ' ' << y <<'\n';


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