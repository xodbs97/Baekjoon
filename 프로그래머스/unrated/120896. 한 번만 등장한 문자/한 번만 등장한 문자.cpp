#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(auto c : s){
        if(m.find(c) != m.end()){
            m.find(c)->second += 1;
        }else{
            m.insert(make_pair(c, 1));
        }
    }
    for(auto i : m){
        if(i.second == 1){
            answer += i.first;
        }
    }
    return answer;
}