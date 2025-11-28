#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool code = false, chef = false;
  for(int i = 0; i <= n - 4; i++){
    if(s.substr(i, 4) == "code") {
        if(chef){
            cout << "WA\n";
        }else{
            cout << "AC\n";
            return;
        }
        code = true;
    }
    if(s.substr(i, 4) == "chef") {
        if(!code){
            cout << "WA\n";
            return;
        }
        chef = true;
    }
    //if(code and chef) code = chef = false;
  }
//   if(code and chef){
//       cout << "AC\n";
//       return;
//   }

  cout << "AC\n";
  return;
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