#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int size = spell.size();
    
    for(string s : dic){
        if(s.length() != size){
            continue;
        }
        int check = 0;
        for(auto c : spell){
            if(s.find(c) == string::npos){
                continue;
            }else{
                check++;
            }
        }
        if(check == size){
            return 1;
        }
    }
    
    return 2;
}