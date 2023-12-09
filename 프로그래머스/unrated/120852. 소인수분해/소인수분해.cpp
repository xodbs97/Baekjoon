#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int div = 2;
    while(n > 1){
        int q = n % div;
        if(q == 0){
            while(q == 0){
                n /= div;
                q = n % div;
            }
            answer.push_back(div);
        }
        div++;
    }
    return answer;
}