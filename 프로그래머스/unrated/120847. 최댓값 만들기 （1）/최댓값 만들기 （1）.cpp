#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int max1 = 0;
    int max2 = 0;
    int temp = 0;
    int idx = numbers.size() - 1;
    while(idx != -1){
        temp = numbers[idx];
        if(temp > max1){
            max2 = max1;
            max1 = temp;
        }else if(temp > max2){
            max2 = temp;
        }
        --idx;
    }
    answer = max1 * max2;
    return answer;
}