#include <bits/stdc++.h>
#define uint unsigned long long
#define int long long
using namespace std;


void solve()
{
    int n;
    cin >> n;

    struct Item {
        int needOpen;   
        int needClose;  
        int idx;        
    };

    vector<Item> pos, neg; 

    auto computeNeeds = [](const string &s) {
        int needOpen = 0, open = 0;
        for (char c : s) {
            if (c == '(') {
                ++open;
            } else {
                if (open > 0) {
                    --open;
                } else {
                    ++needOpen; 
                }
            }
        }
        int needClose = open; 
        return pair<int,int>{needOpen, needClose};
    };

    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        auto [needOpen, needClose] = computeNeeds(strs[i]);
        if (needClose >= needOpen) {
            pos.push_back({needOpen, needClose, i + 1});
        } else {
            neg.push_back({needOpen, needClose, i + 1});
        }
    }

    // Sort positives by needOpen ascending (less risk of early negative balance)
    sort(pos.begin(), pos.end(), [](const Item &a, const Item &b) {
        if (a.needOpen != b.needOpen) return a.needOpen < b.needOpen;
        return a.needClose > b.needClose;
    });

    // Sort negatives by needClose descending (those requiring more trailing closes go first)
    sort(neg.begin(), neg.end(), [](const Item &a, const Item &b) {
        if (a.needClose != b.needClose) return a.needClose > b.needClose;
        return a.needOpen < b.needOpen;
    });

    vector<int> order;
    order.reserve(n);
    for (auto &it : pos) order.push_back(it.idx);
    for (auto &it : neg) order.push_back(it.idx);

    // Validate by simulating balance
    int balance = 0;
    for (int id : order) {
        for (char c : strs[id - 1]) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                cout << "impossible\n";
                return;
            }
        }
    }

    if (balance != 0) {
        cout << "impossible\n";
        return;
    }

    for (int id : order) {
        cout << id << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}

//((()