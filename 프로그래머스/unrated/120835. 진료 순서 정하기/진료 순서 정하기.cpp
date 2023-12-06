#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    map<int, int> m;
    
    int idx = 0;
    for(int i : emergency){
        m.insert(pair<int, int>(i, idx));
        ++idx;
    }
    
    for(auto it : m){
        answer.push_back(emergency.size() - it.second);
    }
    
    return answer;
}