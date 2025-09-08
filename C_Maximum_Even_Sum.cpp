#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

bool perfectSquare(uint x)
{
    uint s = sqrt(x);
    return (s * s == x);
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (!(a & 1) and b & 1)
    {
        cout << -1 << '\n';
        return;
    }
    if (a & 1 and b & 1)
    {
        cout << (a * b) + 1 << '\n';
        return;
    }

    if (!(a & 1) and !(b & 1))
    {

        int k = b / 2;
        cout << (a * k) + (b / k) << '\n';
        return;
    }
    if ((a & 1) and !(b & 1))
    {
        if (b % 4 == 2)
            cout << -1 << '\n';
        else
        {
            int k = b / 2;
            cout << (a * k) + (b / k) << '\n';
        }
        return;
    }
    cout << -1 << '\n';
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