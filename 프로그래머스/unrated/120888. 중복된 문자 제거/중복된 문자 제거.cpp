#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char s : my_string){
        if(answer.find(s) == string::npos){
            answer.push_back(s);
        }
    }
    return answer;
}