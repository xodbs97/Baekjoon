#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<vector<int>> list;
    int size = numlist.size();
    for(int i = 0; i < size; i++){
        vector<int> pair(2);
        pair[0] = numlist[i] - n;
        pair[1] = i;
        list.push_back(pair);
    }
    
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            int temp1 = list[i][0] > 0 ? list[i][0] : -list[i][0];
            int temp2 = list[j][0] > 0 ? list[j][0] : -list[j][0];
            if(temp1 > temp2){
                auto temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }else if(temp1 == temp2){
                if(list[i][0] < list[j][0]){
                    auto temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }
    
    for(vector<int> v : list){
        answer.push_back(numlist[v[1]]);
    }
    
    return answer;
}