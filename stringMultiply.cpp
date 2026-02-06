#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    vector<int> result(a.size() + b.size(), 0);
    for(int i = a.size() - 1; i >=0; i--){
        for(int j = b.size() - 1; j >= 0; j--){
            int mul = (a[i] - '0') * (b[j] - '0');
            result[i + j + 1] += (mul % 10);
            result[i + j] += mul / 10;
        }
    }
    int i = 0;
    while(i < result.size() and result[i] == 0) i++;
    for(; i < result.size(); i++) cout << result[i];
    cout << "\n";
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