#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector<int> allDivisors(int n)
{
    vector<int> divs;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                divs.push_back(i);
            else
            {
                divs.push_back(i);
                divs.push_back(n / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

void solve()
{
    int a;
    cin >> a;
    for (int b = 2; b <= 100; b += 2)
    {
        cout << "b: " << b << "\n";
        vector<int> all_divisors = allDivisors(b);
        for (auto i : all_divisors)
        {
            cout << (a * i) + (b / i) << " i:" << i << "\n";
        }
    }
    cout << "\n\n";
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