#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int c;
    cin >> c;

    int bits = 0;
    int temp = c;
    while (temp > 0)
    {
        ++bits;
        temp >>= 1;
    }

    int a = c;
    int b = c << bits; // ensure (b & c) == 0, so equality holds

    cout << a << ' ' << b << '\n';
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




// example c = 13
// shifting same amount of bits. 10110000
// 10110000 = b
//     1011 = c = a
// xor--------
// 10111011

// a xor c

