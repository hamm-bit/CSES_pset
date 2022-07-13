#include <iostream>

#define ll long long

using namespace std;

int main(int argc, char **argv) {
    cin.tie(NULL);
    ll n, in; 
    cin >> n;
    ll sum = n * (n + 1) / 2;

    for (int i = 0; i < n - 1; i++) {
        cin >> in;
        sum -= in;
    }
    cout << sum << "\n";
}