#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;
map<int, int> songs;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    int n, k, unq = 0, ans = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (songs[k] > 0) {
            unq = 0;
            songs.clear();
        }
        songs[k] += 1;
        unq++;
        ans = max(ans, unq);
    }
    cout << ans << "\n";
    return 0;
}