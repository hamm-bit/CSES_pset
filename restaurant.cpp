#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    set<array<int, 2>> s;
    int n, h, t, ans = 0, c = 0;
    cin >> n;
    // Insert the customer's entry and leave time into a set
    // the set will cover the time for which the customers
    // are present at the table. multipled by 2 and added 1
    // to avoid collisions between entry and leave
    for (int i = 0; i < n; i++) {
        cin >> h >> t;
        s.insert({2 * h, 1});
        s.insert({2 * t + 1, -1});
    }
    // Traverse the set and add 1 for all the presenting customers
    // and delete 1 for all leaving customers
    // answer is extracted for the maximum concurrency during the runtime
    for (array<int, 2> o : s) {
        c += o[1];
        ans = max(ans, c);
    }
    cout << ans << "\n";
    return 0;
}