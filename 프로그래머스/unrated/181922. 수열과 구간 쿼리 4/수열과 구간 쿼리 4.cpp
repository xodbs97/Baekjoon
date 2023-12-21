#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto q : queries){
        int s = q[0], e = q[1], k = q[2], d = 0;
        if(k == 0){
            if(s == 0){
                arr[0]++;
            }
            continue;
        }
        while(d < s){
            d += k;
        }
        while(d <= e){
            arr[d]++;
            d += k;
        }
    }
    return arr;
}