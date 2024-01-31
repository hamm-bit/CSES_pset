#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

int BSS(ll *arr, ll x, int n);

int main(int argc, char **argv) {
    int cnt = 0, n; 
    ll sum = 0, a, v_a[200000 + 5], x;

    cin >> n >> x;
    for (int i=0;i<n;i++) {
        cin >> a;
        sum += a;
        v_a[i] = sum;
    }

    cnt = BSS(v_a, x, n);
    std::cout << cnt << "\n";
    return 0;
}


int BSS(ll *arr, ll x, int n) {
    int cnt = 0, i = 0;
    for (i=0;i<n;i++) {
        if(arr[i]==x) {
            cnt++; break;
        } else if(arr[i] > x) {
            break;
        }
    }

    // cout << i << "\n";

    for (int k=i;k<n;k++) {
        int l = 0, r = k, m;
        while (r-l>1) {
            m = (l+r)/2;
            if (arr[k]-arr[m] == x) {
                cnt++;
                break;
            } else if (arr[k] - arr[m] > x) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l!=r) {
            cnt += (arr[k] - arr[l] == x) ? 1 : 0;
            cnt += (arr[k] - arr[r] == x) ? 1 : 0;
        } else {
            cnt += (arr[k] - arr[l] == x) ? 1 : 0;
        }

    }
    return cnt;
}