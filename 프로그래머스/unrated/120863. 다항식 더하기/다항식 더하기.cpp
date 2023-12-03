#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    vector<string> token;
    
    while(polynomial.find(" ") != string::npos){
        string str = polynomial.substr(0, polynomial.find(" "));
        if(str != "+"){
            token.push_back(str);
        }
        polynomial.erase(0, polynomial.find(" ") + 1);
    }
    token.push_back(polynomial);
    
    int numx = 0;
    int num = 0;
    for(string str : token){
        if(str.find("x") != string::npos){
            string numstr = str.substr(0, str.find("x"));
            if(numstr == ""){
                numx += 1;
            }else{
                numx += stoi(numstr);
            }
        }else{
            num += stoi(str);
        }
    }
    
    if(numx == 0){
        answer += to_string(num);
    }else if(num == 0){
        if(numx == 1){
            answer = "x";
        }else{
            answer += to_string(numx) + "x";
        }
    }else{
        if(numx == 1){
            answer += "x + " + to_string(num);
        }else{
            answer += to_string(numx) + "x + " + to_string(num);
        }
    }
    return answer;
}