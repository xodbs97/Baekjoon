#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(auto s : my_string){
        answer += s < 'a' ? s + 32 : s;
    }
    for(int i = 0; i < answer.length(); i++){
        for(int j = i + 1; j < answer.length(); j++){
            if(answer[i] > answer[j]){
                auto t = answer[i];
                answer[i] = answer[j];
                answer[j] = t;
            }
        }
    }
    
    return answer;
}