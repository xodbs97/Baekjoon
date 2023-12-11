#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int remain = 0;
    
    while(chicken >= 10){
        answer += chicken / 10;
        remain = chicken % 10;
        chicken = chicken / 10 + remain;
    }
    
    return answer;
}