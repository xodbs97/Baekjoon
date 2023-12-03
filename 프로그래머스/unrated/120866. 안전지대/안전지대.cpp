#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    vector<vector<int>> bombs;
    vector<int> coordinate(2);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1){
                coordinate[0] = i;
                coordinate[1] = j;
                bombs.push_back(coordinate);
            }
        }
    }
    
    if(bombs.size() == 0){
        return n * n;
    }else{
        if(n == 1 || n == 2){
            return 0;
        }else{
            // 위험 지역 표시
            for(vector<int> bomb : bombs){
                
                for(int i = bomb[0] - 1; i <= bomb[0] + 1; i++){
                    if(i < 0 || i > n - 1){
                        continue;
                    }
                    for(int j = bomb[1] - 1; j <= bomb[1] + 1; j++){
                        if(j < 0 || j > n - 1){
                            continue;
                        }
                        board[i][j] = 1;
                    }
                }
            }
            // 안전 지역 세기
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == 0){
                        ++answer;
                    }
                }
            }
        }
    }

    return answer;
}