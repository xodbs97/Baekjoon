#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int l = A.length();
    for(int i = 0; i < l; i++){
        if(A == B){
            return i < l ? i : l - i;
        }
        string s1 = A.substr(A.length() - 1, 1);
        string s2 = A.substr(0, A.length() - 1);
        A = s1 + s2;
    }
    
    return -1;
}