#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  string s;
  cin >> s;
  vector<int> has(26, 0);
  int max_freq = 0;
  for (char c : s)
  {
      has[c - 'A']++;
      max_freq = max(max_freq, has[c - 'A']);
  }
  cout << max_freq << endl;

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