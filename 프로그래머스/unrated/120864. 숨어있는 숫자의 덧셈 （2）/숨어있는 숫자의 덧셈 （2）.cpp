#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string num = "";
    for(auto c : my_string){
        if(c >= '0' && c <= '9'){
            num += c;
        }else if(num != ""){
            answer += stoi(num);
            num = "";
        }else{
            num = "";
        }
    }
    if(num != ""){
        answer += stoi(num);
    }
    return answer;
}