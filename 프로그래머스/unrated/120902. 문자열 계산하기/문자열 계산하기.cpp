#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    bool add = true;
    while(my_string.find(" ") != string::npos){
        string token = my_string.substr(0, my_string.find(" "));
        my_string.erase(0, my_string.find(" ") + 1);
        
        if(token == "+"){
            add = true;
        }else if(token == "-"){
            add = false;
        }else{
            if(add){
                answer += stoi(token);
            }else{
                answer -= stoi(token);
            }
        }
    }
    if(add){
        answer += stoi(my_string);
    }else{
        answer -= stoi(my_string);
    }
    return answer;
}