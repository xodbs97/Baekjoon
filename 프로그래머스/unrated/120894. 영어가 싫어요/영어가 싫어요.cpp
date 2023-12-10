#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    while(numbers != ""){
        string num = numbers.length() < 5 ? numbers : numbers.substr(0, 5);
        
        if(num.find("zero") != string::npos){
            answer += 0;
            numbers.erase(0, 4);
        }else if(num.find("one") != string::npos){
            answer += 1;
            numbers.erase(0, 3);
        }else if(num.find("two") != string::npos){
            answer += 2;
            numbers.erase(0, 3);
        }else if(num.find("three") != string::npos){
            answer += 3;
            numbers.erase(0, 5);
        }else if(num.find("four") != string::npos){
            answer += 4;
            numbers.erase(0, 4);
        }else if(num.find("five") != string::npos){
            answer += 5;
            numbers.erase(0, 4);
        }else if(num.find("six") != string::npos){
            answer += 6;
            numbers.erase(0, 3);
        }else if(num.find("seven") != string::npos){
            answer += 7;
            numbers.erase(0, 5);
        }else if(num.find("eight") != string::npos){
            answer += 8;
            numbers.erase(0, 5);
        }else if(num.find("nine") != string::npos){
            answer += 9;
            numbers.erase(0, 4);
        }
        answer *= 10;
    }
    return answer / 10;
}