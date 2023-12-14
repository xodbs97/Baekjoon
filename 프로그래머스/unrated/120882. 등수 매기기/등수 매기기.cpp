#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(), 1);
    for(int i = 0; i < score.size(); i++){
        for(int j = 0; j < score.size(); j++){
            if(score[i][0] + score[i][1] < score[j][0] + score[j][1]){
                answer[i]++;
            }
        }
    }
    return answer;
}