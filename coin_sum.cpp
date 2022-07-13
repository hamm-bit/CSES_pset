#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int mxN = 2e5;
int n, x, c[mxN];
set<int> sum_t;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin >> n;
    // sort the input and construct sum bit by bit;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ll sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += c[j];
            sum_t.insert(sum);
        }
    }
    
    auto it = sum_t.begin();
    for (int i = 0; i < n; i++) {
        if (*it > i + 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}