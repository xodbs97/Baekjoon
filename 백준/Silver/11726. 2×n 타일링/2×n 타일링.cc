#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v(1005, 0);
    v[1] = 1;
    v[2] = 2;
    for(int i = 3; i<= 1000; ++i) v[i] = (v[i - 2] + v[i - 1]) % 10007;
    int n;
    cin >> n;
    cout << v[n];
    
    return 0;
}