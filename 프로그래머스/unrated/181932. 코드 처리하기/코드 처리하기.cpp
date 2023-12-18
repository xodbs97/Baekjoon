#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    bool mode = false;
    for(int i = 0; i < code.length(); i++){
        if(code[i] == '1'){
            mode = !mode;
            continue;
        }
        
        if(mode){
            if(i % 2 != 0){
                ret += code[i];
            }
            continue;
        }
        if(i % 2 == 0){
            ret += code[i];
        }
    }
    
    return ret != "" ? ret : "EMPTY";
}