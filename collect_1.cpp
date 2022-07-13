#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;
pair<int, int> num[mxN];


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    // vector<pair<int, int>> s;
    int n, x, ans = 1;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        num[i] = {x, i};
    } sort(num, num + n);

    for (int i = 1; i < n; i++) {
        if (num[i].second < num[i - 1].second) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}