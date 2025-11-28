#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int rem[n], wr[n];
    int max_rem = 0;
    for(auto &i: rem) cin >> i, max_rem = max(i, max_rem);
    for(auto &i: wr) cin >> i;
    int st;
    cin >> st;
    int sum = 0;
    for(int i = 0; i < st; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum + (max_rem * st) << '\n';
     
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