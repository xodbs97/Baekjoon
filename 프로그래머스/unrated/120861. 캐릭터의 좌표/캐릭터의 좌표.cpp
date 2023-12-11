#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2);
    int x = board[0] / 2;
    int y = board[1] / 2;
    for(string s : keyinput){
        if(s == "up"){
            answer[1] = answer[1] < y ? answer[1] + 1 : answer[1];
        }else if(s == "down"){
            answer[1] = answer[1] > -y ? answer[1] - 1 : answer[1];
        }else if(s == "left"){
            answer[0] = answer[0] > -x ? answer[0] - 1 : answer[0];
        }else if(s == "right"){
            answer[0] = answer[0] < x ? answer[0] + 1 : answer[0];
        }
    }
    return answer;
}