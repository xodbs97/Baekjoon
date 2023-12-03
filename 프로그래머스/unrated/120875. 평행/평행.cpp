#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    vector<double> slope(6);
    slope[0] = (double)(dots[0][1] - dots[1][1]) / (dots[0][0] - dots[1][0]);
    slope[1] = (double)(dots[0][1] - dots[2][1]) / (dots[0][0] - dots[2][0]);
    slope[2] = (double)(dots[0][1] - dots[3][1]) / (dots[0][0] - dots[3][0]);
    slope[3] = (double)(dots[1][1] - dots[2][1]) / (dots[1][0] - dots[2][0]);
    slope[4] = (double)(dots[1][1] - dots[3][1]) / (dots[1][0] - dots[3][0]);
    slope[5] = (double)(dots[2][1] - dots[3][1]) / (dots[2][0] - dots[3][0]);
    
    int answer = 0;
    if(slope[0] == slope[5] || slope[1] == slope[4] || slope[2] == slope[3]){
        answer = 1;
    }

    return answer;
}