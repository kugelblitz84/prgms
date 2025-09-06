#include <bits/stdc++.h>
using namespace std;

long long numberSpiral(long long y, long long x) {
    if (x >= y) {
        if (x % 2 == 1) {
            return x * x - y + 1;
        } else {
            return (x - 1) * (x - 1) + y;
        }
    } else {
        if (y % 2 == 1) {
            return (y - 1) * (y - 1) + x;
        } else {
            return y * y - x + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; // number of test cases
    while (t--) {
        long long y, x;
        cin >> y >> x;
        cout << numberSpiral(y, x) << "\n";
    }
    return 0;
}
