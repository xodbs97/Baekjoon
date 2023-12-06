#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int idx = 0;
    while(k-- > 0){
        answer = numbers[idx % numbers.size()];
        idx += 2;
    }
    return answer;
}