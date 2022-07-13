#include "bits-stdc++.h"

using namespace std;
#define ll long long

bool vis[7][7];
int ans = 0;
string in;

void dfs(int u, int v, int a = 0) {
    if (u == 0 && v == 6) {
        if (a == 48) {
            ++ans;
        }
        return;
    }
    vis[u][v] = true;

    if (v > 0 && v < 6 && u > 0 && u < 6) {
        if (vis[u - 1][v - 1] && vis[u + 1][v - 1] && vis[u][v - 1] && \
            vis[u][v + 1] && !vis[u - 1][v] && !vis[u + 1][v]) {
            return;
        }
        if (vis[u - 1][v + 1] && vis[u + 1][v + 1] && vis[u][v + 1] && \
            vis[u][v - 1] && !vis[u - 1][v] && !vis[u + 1][v]) {
            return;
        }
        if (vis[u - 1][v - 1] && vis[u - 1][v + 1] && vis[u - 1][v] && \
            vis[u + 1][v] && !vis[u][v - 1] && !vis[u][v + 1]) {
            return;
        }
        if (vis[u + 1][v - 1] && vis[u + 1][v + 1] && vis[u + 1][v] && \
            vis[u - 1][v] && !vis[u][v - 1] && !vis[u][v + 1]) {
            return;
        }
    }

    if (in[a] == '?' || in[a] == 'L') {
        if (v == 0 && u > 0 && u < 6) {
            if (!vis[u - 1][v] && !vis[u + 1][v]) {
                return;
            }
        }
        if (v && !vis[u][v - 1]) {
            dfs(u - 1, v, a + 1);
        }
    }
    if (in[a] == '?' || in[a] == 'R') {
        if (v == 6 && u > 0 && u < 6) {
            if (!vis[u - 1][v] && !vis[u + 1][v]) {
                return;
            }
        }
        if (v < 6 && !vis[u][v + 1]) {
            dfs(u - 1, v, a + 1);
        }
    }
    if (in[a] == '?' || in[a] == 'L') {
        if (u == 0 && v > 0 && v < 6) {
            if (!vis[u][v - 1] && !vis[u][v + 1]) {
                return;
            }
        }
        if (u && !vis[u - 1][v]) {
            dfs(u - 1, v, a + 1);
        }
    }
    if (in[a] == '?' || in[a] == 'L') {
        if (u == 6 && u > 0 && u < 6) {
            if (!vis[u][v - 1] && !vis[u][v + 1]) {
                return;
            }
        }
        if (u < 6 && !vis[u + 1][v]) {
            dfs(u - 1, v, a + 1);
        }
    }
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    cin >> in;
    dfs(0, 0);
    cout << ans << "\n";
    return 0;
}