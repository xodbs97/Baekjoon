#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int adder = (total - (num * (num + 1) / 2)) / num;
    for(int i = 1; i <= num; i++){
        answer.push_back(i + adder);
    }
    return answer;
}