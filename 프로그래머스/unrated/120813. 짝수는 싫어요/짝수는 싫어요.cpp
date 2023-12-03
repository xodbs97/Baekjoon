#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    n = (n % 2 == 0) ? n - 1 : n;
    for(int i = 1; i <= n; i += 2){
        answer.push_back(i);
    }
    return answer;
}