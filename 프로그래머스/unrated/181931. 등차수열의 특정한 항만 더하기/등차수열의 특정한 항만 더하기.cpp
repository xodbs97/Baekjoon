#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    int i = a;
    
    for(auto b : included){
        if(b){
            answer += i;
        }
        i += d;
    }
    
    return answer;
}