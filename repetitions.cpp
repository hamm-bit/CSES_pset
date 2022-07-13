#include <iostream>

#define ll long long

using namespace std;

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;
    ll f = 1, g = 1;
    for (ll n = 0; line[n] != '\0'; n++) {
        if (line[n] == line[n + 1]) {
            f++;
        } else {
            f = 1;
        }
        if (f > g) {
            g = f;
        }
    }
    cout << g << "\n";
}