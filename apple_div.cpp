#include <iostream>

using namespace std;
#define ll long long

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n, p[20];
    ll s = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i], s += p[i];
    }
    // total possible combination: n = 2 ^ 20
    for (int i = 0; i < (1 << n); i++) {
        // cout << i << ' ' << (1 << n) << '\n';
        // Calculate current subset sums
        ll cs = 0;
        for (int j = 0; j < n; j++) {
            // !!!!!! Bitmask sum checking !!!!!!
            // iterate through list and add all
            // elements to the sums
            if (i >> j & 1) {
                cs += p[j];
            }
        }
        // Accepts the solution if it is smaller than half of the sum
        if (cs <= s / 2) {
            ans = max(ans, cs);
        }
    }
    cout << s - 2 * ans << "\n";
    return 0;
}