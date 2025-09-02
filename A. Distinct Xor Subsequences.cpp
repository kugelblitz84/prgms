#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<unsigned long long> basis;  // XOR basis

    for (auto x : a) {
        // reduce x with current basis
        for (auto b : basis) {
            x = min(x, x ^ b);
        }
        if (x) {
            basis.push_back(x);
        }
    }

    int k = basis.size();
    // number of distinct XORs = 2^k
    cout << (1ULL << k) << "\n";

    return 0;
}

