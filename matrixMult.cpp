#include <iostream>

using namespace std;
#define ll long long

ll matrix[10][10] = {
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
                    };

void mMult(ll A[][10], ll B[][10], ll res[][10]) {
    // matrix multiplication algorithm
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 10; k++)
                res[i][j] += A[i][k] * B[k][j];
        }
    }
}

void copy(ll src[][10], ll dest[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            dest[i][j] = src[i][j];
    }
}

int main(int argc, char **argv) {
    ll a[10][10], res[10][10];
    ll prev[10][10];
    copy(matrix, a);
    copy(a, prev);
    for (ll m = 0; m < 1000000000000; m++) {
        // cout << m << "round\n";
        mMult(prev, matrix, res);
        // for (int i = 0; i < 10; i++) {
        //     for (int j = 0; j < 10; j++) {
        //         cout << res[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";
        copy(res, prev);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << res[i][j] << "\t\t";
        }
        cout << "\n\n";
    }
    return 0;
}

