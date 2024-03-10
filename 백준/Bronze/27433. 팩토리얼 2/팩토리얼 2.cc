#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll fact(ll n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    cout << fact(n);
    
    return 0;
}