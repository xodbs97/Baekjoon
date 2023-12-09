#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    vector<char> a;
    vector<char> b;
    for(int i = 0; i < before.length(); i++){
        a.push_back(before[i]);
        b.push_back(after[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    return a == b ? 1 : 0;
}