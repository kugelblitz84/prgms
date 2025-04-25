#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    sort(b, b + m);
    for(int i = 0; i < n; i++){
        if(i){
            auto t = lower_bound(b, b + m, a[i] + a[i - 1]);
            if(t != b + m){
                if(a[i] < a[i - 1]) a[i] = *t - a[i];
                else a[i] = min(a[i], *t - a[i]);
            }
            if(a[i] < a[i - 1]){
                cout << "NO\n";
                return;
            }
        }else {
            a[i] = min(b[0] - a[i], a[i]);
        }
    }
    cout << "YES\n";
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