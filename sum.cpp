#include <bits/stdc++.h>
#define int long long
using namespace std;

void cal(string ch,int low, int high, map<string,bool> &mp){
	if(mp.find(ch) != mp.end()) return;
	if(ch.size()>18) return;
  int ans = 0;
	for(auto i:ch){
	  ans*=10;
		ans += i - '0';
	}
	if(ans > high) return;
	
	if(ans >= low) mp[ch] = true;
	cal(ch + "6", low, high,mp);
	cal(ch + "9", low, high,mp);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//memset(dp, -1, sizeof(dp));
	int t = 1;
	cin >> t;
	while(t--){
  map<string,bool> mp;
	int l,r;
	cin >> l >> r;
	cal("6",l,r,mp);
	cal("9",l,r,mp);
	cout << mp.size() <<"\n";	  
	} //solve();
	return 0;
}
