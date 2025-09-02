#include <iostream>
#include <map>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // memset(dp,-1,sizeof(dp));
    ll t;
    cin >> t;
    for (ll ii = 1; ii <= t; ii++)
    {
        ll n, k;
        cin >> n >> k;
        ll first_b = 0, second_b = 0;
        ll i = 0;
        ll low = 0, high = n;
        while (high > low)
        {
            ll mid = low + (high - low) / 2;
            if ((mid * (mid + 1)) / 2 < k)
                low = mid + 1;
            else
                high = mid;
        }
        i = high;
        // cout<<i<<endl;
        first_b = n - 1 - i;
        // cout<<first_b<<endl;
        second_b = n - (k - ((i * (i - 1)) / 2));
        // cout<<second_b<<endl;
        for (ll i = 0; i < n; i++)
        {
            if (i == first_b or i == second_b)
                cout << "b";
            else
                cout << "a";
        }
        cout << "\n";
    }
    return 0;
}