#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int p, n, x;
    cin >> p >> n >> x;

    int forward = (x / p) + (x % p); // go down to the row, then move across columns
    int ans = forward;

    int upperCol = (x + p - 1) / p; // first column index whose start is >= x
    int nextPos = upperCol * p;
    if(nextPos <= n){
        int viaNext = upperCol + (nextPos - x);
        ans = min(ans, viaNext);
    }

    int stepsToLast = (n + p - 1) / p;
    int viaLast = stepsToLast + (n - x);
    ans = min(ans, viaLast);

    cout << ans << '\n';
}
int32_t main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}