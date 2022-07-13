#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    ll q, k, k_c, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        k_c = k;
        int c = -1;
        for (; k_c /= 10 > 0; c++) {
            k_c /= 10;
        }
        // cout << c << '\n';
        for (int n = 0; n <= c; n++) {
            if (k > (n + 1) * (pow(10, (n + 1)) - pow(10, n))) {
                k -= (n + 1) * (pow(10, (n + 1)) - pow(10, n));
            } else {
                ll mod = k % (n + 1), q = k / (n + 1);
                x = pow(10, n) - 1 + mod + q;
                ll out = ((int) (x / pow(10, mod))) % 10;
                cout << out << '\n';
                break;
            }
        }
    }
    return 0;
}