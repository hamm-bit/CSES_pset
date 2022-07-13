#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define array ar
#define stack st

bool adj[300][300] = {0}, stay[300] = {0}, visited[300] = {0};
int N, S, poln_pwr = -1;
pair<int, int> V[300];

void DFS(int u, int v, int bee_out = 0) {
    // If the total amount of bees sent out is greater than the limit
    if (bee_out > S) {
        return;
    }
    visited[v] = true;
    bool path = false;
    for (int i = 0; i < N; i++) {
        if (adj[v][i] && !visited[i]) {
            path = true;
            // If consecutive flowers are both absent
            // The following family HAS to stay in
            if (u != -1 && !stay[u]) {
                DFS(v, i, bee_out);
            } else {
                // Else perform ordinary search
                DFS(v, i, (!stay[v]) ? (bee_out + V[v].first) : bee_out);
                stay[v] = !stay[v];
                DFS(v, i, (!stay[v]) ? (bee_out + V[v].first) : bee_out);
            }
        }
    }
    if (!path) {
        if (poln_pwr < bee_out) poln_pwr = bee_out;
    }
}



int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int s, p;
        cin >> s >> p;
        V[i] = {s, p};
        stay[i] = true;
    }
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1] = true;
        adj[v - 1][u - 1] = true;
    }
    
    // Traverse the adjacency matrix, find the vine connection
    // per vertex, start with node 0 to perform a complete search
    
    // Start a BFS from src (0) and raise all propositions along the paths
    // Conditions: 
    //      - No more than two nodes consecutively can have the family absent
    //      - The total leave population canno be greater than S (upper limit)
    DFS(-1, 0);
    
    cout << poln_pwr << "\n";
    return 0;
}