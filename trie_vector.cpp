#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_NODES = 1e5 + 5;
//global arrays and static arrays are initialized with default value(0).
int trie[MAX_NODES][26];     // trie[node][char] = next_node , 
int words_in[MAX_NODES];     // number of words passing through node
int ended_here[MAX_NODES];   // number of words ending at node
int total_words = 1;          // root is at index 0

void insert(const string& s) {
    int node = 0;
    for (char ch : s) {
        int idx = ch - 'a';
        if (trie[node][idx] == 0) {
            trie[node][idx] = total_words++;
        }
        node = trie[node][idx];
        words_in[node]++;
    }
    ended_here[node]++;
}

string search_prefix(const string& s) {
    int node = 0;
    for (char ch : s) {
        int idx = ch - 'a';
        if (trie[node][idx] == 0) return "&not_found&";
        node = trie[node][idx];
    }

    string ans = s;
    while (true) {
        int max_index = -1, max_words = 0;
        for (int i = 0; i < 26; i++) {
            if (trie[node][i] != 0) {
                if (words_in[trie[node][i]] > max_words) {
                    max_words = words_in[trie[node][i]];
                    max_index = i;
                }
            }
        }
        if (max_index == -1) return ans;
        ans += (char)('a' + max_index);
        node = trie[node][max_index];
    }
}

void solve() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    while (ss >> word) {
        insert(word);
    }

    int n;
    cin >> n;
    while (n--) {
        string prefix;
        cin >> prefix;
        cout << search_prefix(prefix) << endl;
    }
}

int32_t main() {
    solve();
    return 0;
}


