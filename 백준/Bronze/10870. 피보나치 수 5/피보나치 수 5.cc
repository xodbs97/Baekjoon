#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> dp(25, 0);
    dp[1] = 1;
    
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n];
    
    return 0;
}