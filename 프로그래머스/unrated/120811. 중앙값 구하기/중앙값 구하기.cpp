#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    // array 정렬하기
    int len = array.size();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array[array.size() / 2];
}