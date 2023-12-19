#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto q : queries){
        bool pFlag = false;
        int min = 1000000;
        for(int i = q[0]; i <= q[1]; i++){
            if(min > arr[i] && arr[i] > q[2]){
                min = arr[i];
                pFlag = true;
                continue;
            }
        }
        if(pFlag){
            answer.push_back(min);
        }else{
            answer.push_back(-1);
        }
    }
    
    return answer;
}