#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sq = i * i, tot = sq * (sq - 1) / 2;
        if (n >= 2) {
            tot -= 4 * (i - 1) * (i - 2);
        }
        cout << tot << "\n";
    }
    return 0;
}