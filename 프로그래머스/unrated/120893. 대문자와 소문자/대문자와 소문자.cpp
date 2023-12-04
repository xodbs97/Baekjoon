#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto c : my_string){
        if(c <= 'Z'){
            answer.push_back(c + 32);
        }else{
            answer.push_back(c - 32);
        }
    }
    return answer;
}