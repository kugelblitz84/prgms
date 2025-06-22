#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

void solve()
{
    const int n = 5;
    float prio[n], size[n];
    for (auto &i : prio) cin >> i;
    for (int i = 0; i < n; i++) {
        float t;
        cin >> t;
        size[i] = t;
        prio[i] /= t;
    }

    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (prio[j] > prio[index]) {
                index = j;
            }
        }
        if (index != i) {
            swap(prio[i], prio[index]);
            swap(size[i], size[index]);
        }
    }

    float ans = 0, capacity = 50.0;
    for (int i = 0; i < n and capacity > 0; i++) {
        float take = min(capacity, size[i]);
        ans += take * prio[i]; 
        capacity -= take;
    }

    cout << "Total priority: " << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
