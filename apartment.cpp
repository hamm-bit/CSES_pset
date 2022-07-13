#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define l_next 2e5


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    vector<int> g, e;

    int n, m, k, a, b, ans = 0;
    cin >> n >> m >> k;
    // cout << n << m << k;
    assert(m <= n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        g.push_back(a);
    } sort(g.begin(), g.end());
    
    for (int i = 0; i < m; i++) {
        cin >> b;
        e.push_back(b);
    } sort(e.begin(), e.end());
    
    int i_a = 0, i_b = 0;
    while (i_a < n && i_b < m) {
        if (abs(g[i_a] - e[i_b]) <= k) {
            ans++, i_a++, i_b++;
        } else if (g[i_a] < e[i_b]) {
            i_a++;
        } else {
            i_b++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}