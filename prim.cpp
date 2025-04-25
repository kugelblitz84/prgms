#include <bits/stdc++.h>

using namespace std;

 void solve(){
 	int n;
 	cin>>n;
 	int arr[n];
 	for(auto &i:arr) cin>> i;
 	int temp = arr[0];
 	for(int i = 1;i<n;i++){
 		cout<<arr[i]<<" ";
 	}
 	cout<<temp<<endl;

 }
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//pref();
	cin>>t;
	while(t--) solve();
	return 0;
}