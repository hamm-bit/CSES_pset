#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

int main (int argc, char** argv) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int set[26] = {}, odd = 0;
    
    // frequency counter
    for (int i = 0; i < s.size(); i++) {
        set[s[i] - 'A']++;
    }
    // if more than one odd freq letter exist, no solution
    for (int i = 0; i < 26; i++) {
        odd += (set[i] & 0x1);
    }

    if (odd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    // find the odd frequency letter and place them as central num
    // lay out the string order and print to create palindrome
    string t;
    for (int i = 0; i < 26; i++) {
        if (set[i] & 1^1) {
            for (int j = 0; j < set[i] / 2; j++) {
                t += (char) ('A' + i);
            }
        }
    }
    cout << t;
    for (int i = 0; i < 26; i++) {
        if (set[i] & 1) {
            for (int j = 0; j < set[i]; j++) {
                cout << (char) ('A' + i);
            }
        }
    }
    
    reverse(t.begin(), t.end());
    cout << t << "\n";
    return 0;
}