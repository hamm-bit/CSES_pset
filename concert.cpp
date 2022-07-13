#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    set<array<int, 2>> s;
    int n, m, h, t, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> h;
        s.insert({h, i});
    }
    // For each customer, use the lower bound func to determine
    // the ticket within the customer's acceptance range
    // if no ticket is found to be within the customer's acceptance range
    // print -1 for that customer
    // else cout the price of that acceptable ticket and remove it from the array
    for (int i = 0; i < m; i++) {
        cin >> t;
        auto it = s.lower_bound({t + 1, 0});
        if (it == s.begin()) {
            cout << "-1\n";
        } else {
            it--;
            cout << (*it)[0] << "\n";
            s.erase(it);
        }
    }
    return 0;
}