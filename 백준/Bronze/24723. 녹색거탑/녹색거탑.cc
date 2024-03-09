#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int ans = 1;
    while (n--) {
        ans *= 2;
    }
    cout << ans;
    
    return 0;
}