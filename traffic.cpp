#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;
int p[mxN];
map<int, int> mp;
set<int> s;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    int n, x;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    mp[x] = 1;

    // Initialize the road to a set
    // When input is cached, find the input to-be
    // position in the set, the element to the right
    // and the left of the insert pos.
    // Log the distance in a map by using it as idx
    // (Remove the previous dist, add to divided dist)
    // The greatest distance is the last valid element in map
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        auto it = s.lower_bound(p[i]);
        int r = *it;
        it--;
        int l = *it;
        mp[r - l]--;
        if (!mp[r - l]) {
            mp.erase(r - l);
        }
        s.insert(p[i]);
        mp[r - p[i]]++;
        mp[p[i] - l]++;
        cout << ((--mp.end())->first) << "\n";
    }
    
    return 0;
}