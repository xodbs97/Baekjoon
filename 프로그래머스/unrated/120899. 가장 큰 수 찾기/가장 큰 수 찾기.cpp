#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int max_val = 0;
    int max_idx = 0;
    int idx = 0;
    for(int i : array){
        if(i > max_val){
            max_val = i;
            max_idx = idx;
        }
        idx++;
    }
    answer.push_back(max_val);
    answer.push_back(max_idx);
    return answer;
}