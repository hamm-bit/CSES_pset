#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int cnt, first, second;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        cin >> first >> second;
        if ((first + second) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}