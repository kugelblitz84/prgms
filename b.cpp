#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
     string s = "999";
     s[0]--;
     cout << s;
}
int32_t main() {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
    //memset(dp,-1,sizeof(dp));

     //gen();
     int t = 1;
     //cin >> t;
     for(int i = 1; i <= t; i++){
          //cout << "Case " << i <<": "; 
          solve();
     } 
     return 0;
}