#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    for(int i = 1; i < numLog.size(); i++){
        int d = numLog[i] - numLog[i - 1];
        if(d == 1){
            answer += 'w';
        }else if (d == -1){
            answer += 's';
        }else if (d == 10){
            answer += 'd';
        }else{
            answer += 'a';
        }
    }
    
    return answer;
}