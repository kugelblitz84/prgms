#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t > 0){
            ans += t;
        }else{
            t *= -1;
            ans -= min(ans, t);
        }
    }
    cout << ans << "\n";
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