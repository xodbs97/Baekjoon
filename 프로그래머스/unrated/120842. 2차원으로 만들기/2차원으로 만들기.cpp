#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> v(n);
    
    int idx = 0;
    for(int i : num_list){
        v[idx++ % n] = i;
        if(idx % n == 0){
            answer.push_back(v);
        }
    }
    return answer;
}