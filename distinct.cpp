#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    set<int> cnt;
    
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt.insert(x);
    }
    cout << cnt.size() << "\n";
    return 0;
}
