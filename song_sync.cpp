#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN = 2e5;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    // Problem input:
    // first line: n representing the length of the word
    // second line: n words inside the array to represent the lyrics
    //              these words may not be unique to each other

    // 1 <= n <= 2e5

    // output: a list of integers representing the valid offset


    // The task:
    // To find the index difference between all duplicate set elements

    
    set<int> diff;
    map<int, map<int,int>> pos;
    int n, lyr[mxN];
    map<int, int>::iterator it;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lyr[i];
        for (it = pos[lyr[i]].begin(); it != pos[lyr[i]].end(); it++) {
            diff.insert(i - (*it).first);
        }
        pos[lyr[i]][i] = 1;
    }

    for (set<int>::iterator out = diff.begin(); out != diff.end(); out++) {
        cout << (*it).first << " ";
    } cout << "\n";
    return 0;
}