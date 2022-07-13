#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s[8];
bool t[15];

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    int p[8], ans = 0;
    iota(p, p + 8, 0);
    do {
        // simply permutation around coloumns
        // reject reserved squares
        bool ok = 1;
        for (int i = 0; i < 8; i++) {
            ok &= (s[i][p[i]] == '.');
        }
        // reject diagonal cases
        // guaranteed to attack another queen
        memset(t, 0, 15);
        for (int i = 0; i < 8; i++) {
            if (t[i + p[i]]) {
                ok = false;
            } t[i + p[i]] = true;
        }
        memset(t, 0, 15);
        for (int i = 0; i < 8; i++) {
            if (t[i + 7 - p[i]]) {
                ok = false;
            } t[i + 7 - p[i]] = true;
        }
        ans += ok;
    } while (next_permutation(p, p + 8));
    cout << ans << "\n";
}
