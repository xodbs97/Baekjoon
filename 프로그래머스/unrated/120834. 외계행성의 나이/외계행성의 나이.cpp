#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    vector<int> num;
    while(age > 0){
        num.push_back(age % 10);
        age /= 10;
    }
    
    for(int i = num.size() - 1; i >= 0; i--){
        answer += 'a' + num[i];
    }
    
    return answer;
}