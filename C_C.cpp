#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;

static bool disjoint(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.first || b.second < a.first;
}

void solve() {
    int x, y;
    cin >> x >> y;

    vector<pair<int, int>> prodSegs;
    for (int d = 1; d * d <= y; ++d) {
        if (y % d == 0) {
            int e = y / d;
            int L = min(d, e);
            int R = max(d, e);
            prodSegs.push_back({L, R});
        }
    }

    auto outputPair = [](const pair<int, int> &firstSeg, const pair<int, int> &secondSeg) {
        cout << firstSeg.first << " " << firstSeg.second << '\n';
        cout << secondSeg.first << " " << secondSeg.second << '\n';
    };

    int floorHalf = x / 2;

    // Try to place a sum segment completely to the right of a product segment
    for (const auto &seg : prodSegs) {
        if (floorHalf > seg.second) {
            int L = floorHalf;
            int R = x - L;
            pair<int, int> sumSeg = {L, R};
            if (L <= R && disjoint(sumSeg, seg)) {
                outputPair(sumSeg, seg);
                return;
            }
        }
    }

    // Try to place a sum segment completely to the left of a product segment
    for (const auto &seg : prodSegs) {
        int minL = x - seg.first + 1;
        if (minL < 0) minL = 0;
        if (minL <= floorHalf) {
            int L = minL;
            int R = x - L;
            pair<int, int> sumSeg = {L, R};
            if (L <= R && disjoint(sumSeg, seg)) {
                outputPair(sumSeg, seg);
                return;
            }
        }
    }

    if (prodSegs.size() >= 2) {
        sort(prodSegs.begin(), prodSegs.end());
        pair<int, int> best = prodSegs.front();
        for (size_t i = 1; i < prodSegs.size(); ++i) {
            if (disjoint(best, prodSegs[i])) {
                outputPair(best, prodSegs[i]);
                return;
            }
            if (prodSegs[i].second < best.second) {
                best = prodSegs[i];
            }
        }
    }

    cout << -1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

