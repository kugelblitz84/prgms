#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i=0;i<n;++i) cin >> p[i];
    // Construct q_i = (n+1) - p_i. Then p_i + q_i = n+1 constant.
    // Since n >=2, n+1 >=3 and gcd of identical constants is that constant (>=3).
    for(int i=0;i<n;++i){
        long long q = (long long)n + 1 - p[i];
        cout << q << (i+1==n?'\n':' ');
    }
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