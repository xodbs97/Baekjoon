#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while(order > 0){
        int r = order % 10;
        if(r){
            answer += r % 3 ? 0 : 1;
        }
        order /= 10;
    }
    return answer;
}