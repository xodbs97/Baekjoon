#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(auto c : my_string){
        if(c >= '0' && c <= '9'){
            answer.push_back((int)c - '0');
        }
    }
    for(int i = 0; i < answer.size(); i++){
        for(int j = i + 1; j < answer.size(); j++){
            if(answer[i] > answer[j]){
                auto temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}