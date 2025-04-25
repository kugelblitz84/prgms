#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int32_t l,r;
    cin >> l >> r;
    int32_t k = 31 - __builtin_clz(l ^ r);
    cout << k << endl;
    
}

//1 1   2 2   3 3 3 3   4 4 4

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