#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(string str : quiz){
        vector<string> token;

        while(str.find(" ") != string::npos){
            token.push_back(str.substr(0, str.find(" ")));
            str.erase(0, str.find(" ") + 1);
        }
        int sum = 0;
        if(token[1] == "+"){
            sum = stoi(token[0]) + stoi(token[2]);
        }else{
            sum = stoi(token[0]) - stoi(token[2]);
        }
        int result = stoi(str);
        if(sum == result){
            answer.push_back("O");
        }else{
            answer.push_back("X");
        }
    }
    
    return answer;
}