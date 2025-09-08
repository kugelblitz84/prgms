#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;


uint bin_exp(uint a, uint b)
{
    uint res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % 1000000007;
        a = a * a % 1000000007;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    cout << bin_exp(2, n) << "\n";

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}