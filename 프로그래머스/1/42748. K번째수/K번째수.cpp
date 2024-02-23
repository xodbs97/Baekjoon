#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> cmd : commands) {
        int be = cmd[0] - 1, en = cmd[1], k = cmd[2] - 1;
        vector<int> v = array;
        sort(v.begin() + be, v.begin() + en);
        answer.push_back(v[be + k]);
    }
    
    return answer;
}