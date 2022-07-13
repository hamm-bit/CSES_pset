#include <iostream>

using namespace std;

#define ll long long

int main (int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    ll y, x;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;
        if (x % 2 == 1) {
            if (x >= y) {
                cout << x * x - y + 1 << "\n";
            }
        } else if (y % 2 == 0) {
            if (y >= x) {
                cout << y * y - x + 1 << "\n";
            }
        } else {
            cout << y * y + x << "\n";
        }
    }
    return 0;
}
