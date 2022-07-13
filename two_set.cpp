#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main (int argc, char** argv) {
    // n mod 4 = 0 or 3
    int n, first_i, second_i;
    cin >> n;
    vector<int> first, second;
    
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO";
        return 0;
    } else if (n % 4 == 0) {
        first_i = n / 2;
        second_i = n / 2;
        for (int i = 0; i < n / 4; i++) {
            first.push_back(i * 4 + 1);
            first.push_back(i * 4 + 4);
            second.push_back(i * 4 + 2);
            second.push_back(i * 4 + 3);
        }
    } else {
        first_i = n / 2 + 1;
        second_i = n / 2;
        first.push_back(1);
        first.push_back(2);
        second.push_back(3);
        for (int i = 0; i < n / 4; i++) {
            first.push_back(i * 4 + 1 + 3);
            first.push_back(i * 4 + 4 + 3);
            second.push_back(i * 4 + 2 + 3);
            second.push_back(i * 4 + 3 + 3);
        }
    }

    cout << "YES\n" << first_i << "\n";
    for (int i = 0; i < first_i; i++) {
        cout << first[i] << " ";
    }
    cout << "\n" << second_i << "\n";
    for (int i = 0; i < second_i; i++) {
        cout << second[i] << " ";
    }
    cout << "\n";
    return 0;
}