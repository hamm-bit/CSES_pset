#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;

int med[mxN] = {0};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    // vector<pair<int, int>> s, e;
    int n, x, mid, mod;
    ll diff = 0;
    ll msf = -1e18, ans = -1e18;
    cin >> n;

    // find the median of the list
    for (int i = 0; i < n; i++) {
        cin >> med[i];
    } sort(med, med + n);
    mid = med[n / 2];
    for (int i = 0; i < n; i++) {
        diff += abs(med[i] - mid);
    }
    cout << diff << "\n";
    return 0;
}