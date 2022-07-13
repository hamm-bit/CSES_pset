#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;
    if (n < 5) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 0; i < n / 2; i++) {
        cout << i * 2 + 1 << " "; 
    }
    if (n % 2) {
        cout << n << " ";
    }
    for (int i = 1; i <= n / 2; i++) {
        cout << i * 2 << " ";
    }
    return 0;
}