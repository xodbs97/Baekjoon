#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; // 300 이하의 자연수인 계단의 개수
    cin >> n;
    vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> v[i];
    
    vector<int> dp(n + 1, 0); 
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    
    for(int stair = 3; stair <= n; ++stair) 
        dp[stair] = v[stair] + max(dp[stair - 2], dp[stair - 3] + v[stair - 1]);
    cout << dp[n];
    
    return 0;
}