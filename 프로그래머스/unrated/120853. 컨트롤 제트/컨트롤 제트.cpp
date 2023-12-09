#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int adder = 0;
    while(s.find(" ") != string::npos){
        string n = s.substr(0, s.find(" "));
        s.erase(0, s.find(" ") + 1);
        if(n != "Z"){
            adder = stoi(n);
            answer += adder;
        }else{
            answer -= adder;
        }
    }
    if(s != "Z"){
        adder = stoi(s);
        answer += adder;
    }else{
        answer -= adder;
    }
    return answer;
}