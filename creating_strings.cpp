#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define long long ll

int main(int argc, char **argv) {
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << "\n";
    for (string a : ans) {
        cout << a << "\n";
    }
    return 0;
}