#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    for(auto v : db){
        if(v[0] == id_pw[0]){
            return v[1] == id_pw[1] ? "login" : "wrong pw";
        }
    }
    return "fail";
}