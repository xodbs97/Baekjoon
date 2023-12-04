#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    for(auto c : rsp){
        answer +=  c == '0' ? "5" : c == '2' ? "0" : "2";
    }
    return answer;
}