#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

int find_gcd(int t){
    for(int i = 2; i <= t + 1; i++){
        //cout << i << " " << t << ": " << __gcd(i, t) << "\n";
        if(__gcd(i, t) == 1) return i;
    }
    return 2;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 1e18 + 7;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        ans = min(ans, find_gcd(t));
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


