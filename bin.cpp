#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        // If k = 1, we can only subtract 1 each time.
        cout << n << "\n";
        return;
    }

    int operations = 0;

    // Count the number of non-zero digits in base k representation
    while (n > 0) {
        if (n % k != 0) {
            operations++; // Count non-zero digit
        }
        n /= k; // Move to the next digit in base k
    }

    cout << operations << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
