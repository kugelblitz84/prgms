#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long p , r, g, x;
    cin >> p >> r >> g >> x;
    long long per_teacher = min(r, g * x);
    cout << p * per_teacher << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
