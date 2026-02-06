#include <bits/stdc++.h>
#define int long long
using namespace std;

// Compute costs: f = cost to make evenly even, s = cost to make oddly odd
pair<int, int> computeCosts(int x) {
    int f = 0; // cost to remove all odd prime factors (evenly even)
    int s = 0; // cost to remove all factors of 2 (oddly odd)
    
    // Count and remove factors of 2
    while (x % 2 == 0) {
        s += 2;
        x /= 2;
    }
    
    // Remove odd prime factors
    for (int p = 3; p * p <= x; p += 2) {
        while (x % p == 0) {
            f += p;
            x /= p;
        }
    }
    if (x > 1) {
        f += x; // x is a prime > sqrt(original)
    }
    
    return {f, s};
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<pair<int, int>> costs(n); // {f_i, s_i}
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        costs[i] = computeCosts(x);
    }
    
    // Sort by (f_i - s_i) in non-decreasing order
    // Elements with smaller (f - s) prefer to be evenly even
    sort(costs.begin(), costs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return (a.first - a.second) < (b.first - b.second);
    });
    
    // Compute prefix sums
    // For x evenly even: first x elements -> evenly even, rest -> oddly odd
    // Cost = sum of f_i for first x + sum of s_i for last (n-x)
    vector<int> prefixF(n + 1, 0), prefixS(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixF[i + 1] = prefixF[i] + costs[i].first;
        prefixS[i + 1] = prefixS[i] + costs[i].second;
    }
    
    int ans = LLONG_MAX;
    // x = number of evenly even elements
    // Need at least 'a' evenly even, at least 'b' oddly odd
    // So: x >= a and (n - x) >= b  =>  a <= x <= n - b
    for (int x = a; x <= n - b; x++) {
        int cost = prefixF[x] + (prefixS[n] - prefixS[x]);
        ans = min(ans, cost);
    }
    
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}