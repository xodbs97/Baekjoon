#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int size = num_list.size();
    vector<int> answer(size);
    for(int i : num_list){
        answer[size - 1] = i;
        --size;
    }
    
    return answer;
}