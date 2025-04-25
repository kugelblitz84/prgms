#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int arr[n];
  int mp[31] = {0};
  for(auto &i: arr){
    cin >> i;
    for(int j = 0; j <= 30; j++){
        
        if(i & (1ll << j)) mp[j]++;
    }
  }
  int ans = -1e18, el = arr[0];
  for(auto i: arr){
    int cur_max = 0;
for (int j = 0; j <= 30; j++) {
    if (i & (1 << j)) {
        cur_max += (n - mp[j]) * (1 << j) * 1ull;
    } else {
        cur_max += mp[j] * (1 << j) * 1ull;
    }
}

    if(cur_max > ans){
        ans = cur_max;
        el = i;
    }

  } 
  // int sum = 0;
  // for(auto i: arr){
  //   sum += el ^ i;
  // }
  cout << ans << '\n';

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