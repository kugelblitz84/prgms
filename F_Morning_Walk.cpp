#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int L, v0, T, n;
    cin >> L >> v0 >> T >> n;
    while(n--){
        int ti, vi;
        cin >> ti >> vi;
        int remDist = v0 * (T - ti);
        if(vi > 0){
            cout << (v0 < vi ? ((remDist * (vi - v0)) / (L * v0)) : ((remDist * (v0 - vi)) / (L * v0))) + 1;
        }else cout << ((remDist * (v0 - vi)) / (L * v0)) + 1;

        if(n) cout << ' ';
    }
    cout << '\n';
  
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