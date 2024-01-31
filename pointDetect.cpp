#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;

struct pairSecondCmp {
    constexpr bool operator()(const pair<int, int> p1,\
                              const pair<int, int> p2)
    {
        return p1.second < p2.second;
    }
};

int main(int argc, char **argv) {
    int n, m, s;
    int a, b;
    string command;
    priority_queue<pair<int, int>, vector<pair<int, int>>, pairSecondCmp> here;

    cin >> n;
    for (int i = 0; i < n; i++) {
        if (command == "add") {
            cin >> a >> b;
            here.push({a, b});
        }
    }

    
}