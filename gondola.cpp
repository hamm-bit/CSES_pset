#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    int g[mxN] = {0};

    int n, x, p, ans = 0;
    cin >> n >> x;
    // cout << n << m << k;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    } sort(g, g + n);
    
    for (int i = 0, j = n - 1; i < j;) {
        while (i < j && (g[i] + g[j]) > x) {
            j--;
        }
        if (i >= j) {
            break;
        }
        ans++, i++, j--;
    }
    
    cout << n - ans << "\n";
    return 0;
}