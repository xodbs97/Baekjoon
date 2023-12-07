#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> rev_ans;
    for(int i = 1; i <= n / i; i++){
        if(n % i == 0){
            answer.push_back(i);
            if(i == n / i){
                break;
            }
            rev_ans.push_back(n / i);
        }
    }
    for(int i = rev_ans.size() - 1; i >= 0; i--){
        answer.push_back(rev_ans[i]);
    }
    
    return answer;
}