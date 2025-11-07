#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i: arr) cin >> i;
    sort(arr.begin(), arr.end());
    int median = arr[n >> 1];
    int index = n >> 1;
    while(upper_bound(arr.begin() + index, arr.end(), median) != arr.end() and k > 0){
        int next_median = *(upper_bound(arr.begin() + index, arr.end(), median));
        int diff = next_median - median;
        int count = upper_bound(arr.begin() + index, arr.end(), median) - (arr.begin() + index);
        int total_cost = diff * count;
        if(total_cost <= k){
            median = next_median;
            k -= total_cost;
        }
        else{
            median += k / count;
            k = 0;
        }
    }
    if(k > 0){
        int count = upper_bound(arr.begin() + index, arr.end(), median) - (arr.begin() + index);
        median += k / count;
    }
    cout << median << '\n';
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