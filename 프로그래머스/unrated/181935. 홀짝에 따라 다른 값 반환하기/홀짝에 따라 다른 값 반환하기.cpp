#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n == 1){
        return 1;
    }
    
    int answer = 0;

    if(n % 2 == 0){
        while(n){
            answer += n * n;
            n -= 2;
        }
        return answer;
    }
    
    int i = (n + 1) / 2;
    
    return i * i;
}