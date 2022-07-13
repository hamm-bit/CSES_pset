#include <bits/stdc++.h>

// Interval Scheduling problem

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    // vector<pair<int, int>> s, e;
    int n, x, a, idx = 0;
    cin >> n >> x;
    map<int, int> mp;

    // Use a map to contain the incoming int
    // As the incoming int is inserted, search is performed to find
    // potential matching number to be faired and outputted
    // If no fair is found at the end of the loop, call
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (mp.find(x - a) != mp.end()) {
            cout << mp[x - a] + 1 << " " << i + 1;
            return 0;
        }
        mp[a] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}