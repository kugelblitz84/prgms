#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // Map each book to its position in the stack
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[a[i]] = i;

    int cur = 0; // pointer to topmost book still in the stack
    for (int i = 0; i < n; i++) {
        int book = b[i];
        if (pos[book] >= cur) {
            // move all books from cur to pos[book]
            int moved = pos[book] - cur + 1;
            cout << moved << " ";
            cur = pos[book] + 1; // update top pointer
        } else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
    return 0;
}
