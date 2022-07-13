#include <iostream>

#define ll long long

using namespace std;

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll init;
    cin >> init;

    while (init != 1) {
        if (init % 2 == 0) {
            init /= 2;
        } else {
            init = init * 3 + 1;
        }
        cout << init << " ";
    }
    cout << "\n";
}