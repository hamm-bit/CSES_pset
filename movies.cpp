#include <bits/stdc++.h>

// Interval Scheduling problem

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    vector<pair<int, int>> s, e;
    int n, h, t, ans = 0;
    cin >> n;
    // For each customer, use the lower bound func to determine
    // the ticket within the customer's acceptance range
    // if no ticket is found to be within the customer's acceptance range
    // print -1 for that customer
    // else cout the price of that acceptable ticket and remove it from the array
    for (int i = 0; i < n; i++) {
        cin >> h >> t;
        e.push_back({t, h});
    } sort(e.begin(), e.end());

    int low = 0;
    for (int i = 0; i < n; i++) {
        if (e[i].second >= low) {
            ans++;
            low = e[i].first;
        }
    }
    cout << ans << "\n";
    return 0;
}