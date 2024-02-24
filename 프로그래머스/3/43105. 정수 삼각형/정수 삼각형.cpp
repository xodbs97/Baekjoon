#include <bits/stdc++.h>

using namespace std;

vector<int> dp(130000);

int triangleCount(int n) {
    return (n + 1) * n / 2;
}

int solution(vector<vector<int>> triangle) {
    if ((int)triangle.size() == 1) return triangle[0][0];
    
    int length = (int)triangle.size();
    int lastIdx = triangleCount(length);
    
    dp[1] = triangle[0][0];
    
    int idx = 2;
    for (int i = 1; i < triangle.size(); ++i) {
        for(int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[idx] = dp[idx - i] + triangle[i][j];
                ++idx;
                continue;
            }
            if (j == i) {
                dp[idx] = dp[idx - i - 1] + triangle[i][j];
                ++idx;
                continue;
            }
            dp[idx] = max(dp[idx - i - 1], dp[idx - i]) + triangle[i][j];
            ++idx;
        }
    }
    int answer = 0;
    for(int i = lastIdx - length + 1; i <= lastIdx; ++i) {
        answer = max(answer, dp[i]);
    }
    
    return answer;
}