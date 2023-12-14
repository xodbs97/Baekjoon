#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int b1 = stoi(bin1, nullptr, 2);
    int b2 = stoi(bin2, nullptr, 2);
    int sum = b1 + b2;
    if(sum == 0){
        return "0";
    }
    int d = 1;
    while(sum - d >= 0){
        d *= 2;
    }
    d /= 2;
    
    while(d > 0){
        if(sum - d >= 0){
            answer += "1";
            sum -= d;
        }else{
            answer += "0";
        }
        d /= 2;
    }
    return answer;
}