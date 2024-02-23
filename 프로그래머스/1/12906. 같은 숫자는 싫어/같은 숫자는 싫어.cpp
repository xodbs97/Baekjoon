#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    queue<int> q;
    for(int i : arr) {
        if(q.empty()) {
            q.push(i);
            continue;
        }
        if (q.back() == i) {
            continue;
        }else{
            q.push(i);
        }
    }
    while(!q.empty()) {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}