#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    int idx = 0;
    for(int i : numbers){
        answer[idx] = 2 * i;
        ++idx;
    }
    return answer;
}