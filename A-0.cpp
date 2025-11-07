#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long swimmers, boats;
    long double riverWidth, swimSpeed, boatSpeed, ans;

    cin >> swimmers >> boats;
    cin >> riverWidth >> swimSpeed >> boatSpeed;

    long double timeIfSwimOnly = riverWidth/swimSpeed;

    if (boatSpeed<=swimSpeed) {
        ans = timeIfSwimOnly;
    } 
    else {
        long double boatToUse = (long double)min(swimmers, boats);

        long double avgBoatBenifit = ((boatSpeed - swimSpeed) * boatToUse)/(boatSpeed * swimmers);

        ans = timeIfSwimOnly - (timeIfSwimOnly * avgBoatBenifit);

        long double timeIfBoatOnly = riverWidth/boatSpeed;
        ans = max(ans, timeIfBoatOnly);
        ans = min(ans, timeIfSwimOnly);
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
}