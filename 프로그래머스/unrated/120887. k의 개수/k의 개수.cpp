#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) { 
    int answer = 0;
    char n = k + '0';
    for(int a = i; a <= j; a++){
        for(auto c : to_string(a)){
            if(c == n){
                answer++;
            }
        }
    }
    return answer;
}