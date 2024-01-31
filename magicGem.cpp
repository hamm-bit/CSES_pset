#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define ll long long

#define nMAX 1e18+5
const long nMOD = 1e9+7;
const int side = 100;

unordered_map<ll, ll> mem;

ll m;
ll DP(ll n) {
    if (n<0) return 0;
    if (n<m) return 1;
    if (mem.find(m)!=mem.end()) return mem[m];

    ll mid = (n+1)/2;
    ll ret = (DP(mid-1)*DP(n-mid))%nMOD;
    for (ll i = 1; i<=m; i++) {
        ret = (ret+(DP(mid-i)*DP(n-m-mid+i))%nMOD)%nMOD;
    }
    return mem[n]=ret;
}

int main(int argc, char **argv) {
    ll n;
    cin >> n >> m;
    mem[0] = 0;
    mem[1] = 1;
    cout << DP(n) << "\n";
    return 0;
}




    // #include<bits/stdc++.h>
    // using namespace std;
     
    // typedef long long int ll;
    // #define MOD 1000000007
    // unordered_map<ll,ll>mem;
    // ll m;
    // ll DP(ll n){
    // if(n<0)return 0;
    // if(n<m)return 1;
    // if(mem.find(n)!=mem.end())return mem[n];
    // ll mid=(n+1)/2,ret=(DP(mid-1)*DP(n-mid))%MOD;
    // for(ll i=1;i<=m;i++){
     
    // ret=(ret+(DP(mid-i)*DP(n-m-mid+i))%MOD)%MOD;
    // }
    // return mem[n]=ret;
    // }
     
    // int main(){
    // ll n;
    // cin>>n>>m;
    // mem[0]=0;
    // mem[1]=1;
    // cout<<DP(n);
    // return 0;
    // }