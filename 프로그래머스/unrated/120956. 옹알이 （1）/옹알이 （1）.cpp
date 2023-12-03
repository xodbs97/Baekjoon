#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(string str : babbling){
        bool flag = false;
        while(true){
            if(str.empty()){
                flag = true;
                break;
            }
            
            if(str.substr(0, 3).compare("aya") == 0){
                str.erase(0, 3);
            }else if(str.substr(0, 2).compare("ye") == 0){
                str.erase(0, 2);
            }else if(str.substr(0, 3).compare("woo") == 0){
                str.erase(0, 3);
            }else if(str.substr(0, 2).compare("ma") == 0){
                str.erase(0, 2);
            }else{
                flag = false;
                break;
            }
        }
        
        if(flag){
            ++answer;
        }
    }
    
    return answer;
}