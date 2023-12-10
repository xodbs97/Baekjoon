#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min = 100;
    for(auto i : array){
        int dif = i - n >= 0 ? i - n : n - i;
        if(min > dif){
            min = dif;
        }
    }
    
    for(auto i : array){
        if(i == n - min){
            return i;
        }
    }
    return n + min;
}