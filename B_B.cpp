#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (x & 1 and y & 1)
    {
        cout << "-1\n";
        return;
    }
    string s1 = "", s2 = "";
    char mid = 'g';
    if (x & 1)
        mid = 'a';
    else if (y & 1)
        mid = 'b';
    s1 = string(x / 2, 'a') + string(y / 2, 'b');
    if (mid != 'g')
        s1 += mid;
    s1 += string(y / 2, 'b') + string(x / 2, 'a');
    s2 = string(y / 2, 'b') + string(x / 2, 'a');
    if (mid != 'g')
        s2 += mid;
    s2 += string(x / 2, 'a') + string(y / 2, 'b');
    if(s1 != s2)cout << s1 << '\n'
         << s2 << '\n';
    else cout << -1 << '\n';
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
