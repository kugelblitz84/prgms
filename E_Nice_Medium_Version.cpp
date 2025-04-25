#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

vector <int> all;
 void gen(string s){
    if(s.size() > 18) return;
    int t = stoll(s);
    if(t > 1e18+2) return;
    all.push_back(t);
    gen(s + "6");
    gen(s + "9");
 }

void solve()
{
    int low, high;
    cin >> low >> high;
    int ans = upper_bound(all.begin(), all.end(), high) - lower_bound(all.begin(), all.end(), low);
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    gen("6");
    gen("9");
    sort(all.begin(), all.end());
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}