#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<int> dp(11, 0);
    dp[0] = m - n;
    vector<int> digits;
    while(m){
        digits.push_back(n % 10);
        n /= 10;
        m /= 10;
    }
    for(int i = 1; i < digits.size(); i++){
        if(dp[i - 1] < (10 - digits[i - 1])){
            break;
        }
        dp[i] = (dp[i - 1] - (10 - digits[i - 1])) / 10;
        dp[i]++;
    }

    for(int i = 0; i < digits.size(); i++){
        ans += dp[i];
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