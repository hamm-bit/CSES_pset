#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    // vector<pair<int, int>> s, e;
    int n, x;
    ll msf = -1e18, ans = -1e18;
    cin >> n;

    // Keep track of consecutive sum
    // If the previous max sum is less than the inserting value
    // Ditch the previous max sum and replace with the currect value
    // If the previous max sum is more than the inserting value
    // Add the current value to the sum
    // Answer is the peak value of max sum
    for (int i = 0; i < n; i++) {
        cin >> x;
        msf = max(0ll + x, msf + x);
        ans = max(ans, msf);
    }
    cout << ans << "\n";
    return 0;
}