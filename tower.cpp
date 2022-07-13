#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;
vector<int> tw;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    int n, k, unq = 0, ans = 0;
    cin >> n;
    
    // find the longest non-decreasing sequence
    // insert element into vector if the sequence is increasing
    // else replace the iterator->element with curr
    // final output is the size of the vector
    for (int i = 0; i < n; i++) {
        cin >> k;
        int it = upper_bound(tw.begin(), tw.end(), k) - tw.begin();
        if (it < tw.size()) {
            tw[it] = k;
        } else {
            tw.push_back(k);
        }
    }
    cout << tw.size() << "\n";
    return 0;
}