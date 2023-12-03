#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    while(true){
        if(n % a == 0){
            ++answer;
        }
        if(n < a){
            break;
        }
        a++;
    }
    return answer;
}