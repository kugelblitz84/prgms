#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(auto &x : arr) cin >> x;
    sort(arr, arr + n);
    int ans = 0;
    for(int i = n - 1, j = 1; i >= 0; i--, j++) {
            ans += arr[i] * m;
            m--;
            if(m == 0) break;
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