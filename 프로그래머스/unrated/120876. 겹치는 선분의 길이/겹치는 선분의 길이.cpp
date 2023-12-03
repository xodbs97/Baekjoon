#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int min = 100;
    int max = -100;
    for(vector<int> dot : lines){
        if(dot[0] <= min){
            min = dot[0];
        }
        if(dot[1] >= max){
            max = dot[1];
        }
    }
    vector<int> line(max - min, 0);
    
    for(vector<int> dot : lines){
        for(int i = dot[0] - min; i < dot[1] - min; i++){
            line[i]++;
        }
    }

    for(int i : line){
        if(i > 1){
            answer++;
        }
    }
    
    return answer;
}